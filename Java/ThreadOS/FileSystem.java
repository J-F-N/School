/*/////////////////////////////////////
Edited by: Parker Amundsen
Last Edit: 03/14/2020
Description: This class is the highest level of the FileSystem manager classes. FileSystem manages the functionality of
the SuperBlock, Directory, and the FileTable classes.
*/////////////////////////////////////

public class FileSystem {
    private SuperBlock superBlock;
    private Directory directory;
    private FileTable fileTable;

    //constants for whence

    public final int SEEK_SET = 0;
    public final int SEEK_CUR = 1;
    public final int SEEK_END = 2;

    // Constructor takes the number of disk blocks, initializes the superblock, directory and filetable with
    // this information
    public FileSystem(int diskBlocks) {
        superBlock = new SuperBlock(diskBlocks);
        directory = new Directory(superBlock.inodeBlocks);
        fileTable = new FileTable(directory);
        // Create root directory
        FileTableEntry dirEnt = open("/", "r");
        int dirSize = fsize(dirEnt);
        if (dirSize > 0) {
            byte[] dirData = new byte[dirSize];
            read(dirEnt, dirData);
            directory.bytes2Directory(dirData);
        }
        close(dirEnt);
    }

    // Synchronizes the filesystem with the disk
    public void sync() {
        FileTableEntry dirEnt = open("/", "w");
        byte[] buffer = directory.directory2Bytes();
        write(dirEnt, buffer);
        close(dirEnt);
        superBlock.toDisk();
    }

    // this reformats the filesystem to support a new number of files.
    // This will lose any stored files in the filesystem
    public boolean format(int files) {
        try {
            while (!fileTable.fempty()) {
                fileTable.wait();
            }
            superBlock.format(files);
            directory = new Directory(superBlock.inodeBlocks);
            fileTable = new FileTable(directory);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    // This will perform a variety of tasks to the given fileName
    // if the mode is W and the file exists, the file will be overwritten and all
    // previous data will be deleted. Other modes will open the existing file
    // and add the file entry to the file table.
    public FileTableEntry open(String fileName, String mode) {
        FileTableEntry entry = fileTable.falloc(fileName, mode);
        if (mode.equals("w")) {
            boolean blockDeallocationSuccess = deallocAllBlocks(entry);
            if (!blockDeallocationSuccess)
                return null;
        }
        return entry;
    }

    // This will remove theFileTable entry from the filetable
    public boolean close(FileTableEntry entry) {
        synchronized (entry) {
            entry.count--;
            if (entry.count > 0) return true;
            return fileTable.ffree(entry);
        }
    }

    // fSize will return the fileSize of the fileEntry
    public int fsize(FileTableEntry entry) {
        synchronized (entry) {
            return entry.inode.length;
        }
    }

    // read with the help of functionality from Inode will read until the end of the
    // file or until the buffer is full. The number of bytes read will be returned or
    // -1 if the entry mode is of the write type
    public int read(FileTableEntry entry, byte[] buffer) {
        if (entry.mode.equals("w") || entry.mode.equals("a")) return -1;

        int bytesRead = 0;
        int bufferRemaining = buffer.length;

        synchronized (entry) {
            int fileSize = fsize(entry);
            // continue until buffer is full or eof is reached
            while (bufferRemaining > 0 && entry.seekPtr < fileSize) {
                // Get the block that the seek ptr is pointed to
                int targetBlock = entry.inode.getTargetBlock(entry.seekPtr);
                if (targetBlock == -1) {
                    return bytesRead;
                }

                // Get the position within the block
                int seekPtrInBlock = entry.seekPtr % 512;
                int remainingBytesInBlock = 512 - seekPtrInBlock;

                // Read this block
                byte[] targetBlockBuffer = new byte[512];
                SysLib.rawread(targetBlock, targetBlockBuffer);
                int remainingBytesInFile = fsize(entry) - entry.seekPtr;

                // Calculate the number of bytes that can be moved into the buffer
                int maximumBytesToRead = (remainingBytesInBlock > bufferRemaining) ? bufferRemaining : remainingBytesInBlock;
                maximumBytesToRead = (maximumBytesToRead > remainingBytesInFile) ? remainingBytesInFile : maximumBytesToRead;

                // Move read bytes into the buffer
                System.arraycopy(targetBlockBuffer, seekPtrInBlock, buffer, bytesRead, maximumBytesToRead);

                // Update pointers
                entry.seekPtr += maximumBytesToRead;
                bytesRead += maximumBytesToRead;
                bufferRemaining -= maximumBytesToRead;
            }
            // finished reading
            return bytesRead;
        }
    }

    // write will return error if the mode is of read type
    // the data from the buffer will be written into available blocks
    // the bytes written will be returned if successful
    public int write(FileTableEntry entry, byte[] buffer) {
        if (entry.mode.equals("r")) return -1;


        int bytesWritten = 0;
        int bufferRemaining = buffer.length;

        synchronized (entry) {
            // continue until buffer is empty
            while (bufferRemaining > 0) {
                // Get target block of seek ptr
                int targetBlock = entry.inode.getTargetBlock(entry.seekPtr);

                // if unavailable get a new block
                if (targetBlock == -1) {
                    int freeBlock = superBlock.getFreeBlock();

                    // assign target block, check for errors
                    switch (entry.inode.setTargetBlock(entry.seekPtr, (short) freeBlock)) {

                        case Inode.ErrorPrecBlockUnused:
                            SysLib.cerr("WRITE ERROR\n");
                            return -1;

                        case Inode.ErrorBlockRegistered:
                            SysLib.cerr("WRITE ERROR\n");
                            return -1;

                        case Inode.ErrorIndirectNull:
                            int nextFreeBlock = superBlock.getFreeBlock();

                            if (!entry.inode.setIndexBlock((short) nextFreeBlock)) {
                                SysLib.cerr("WRITE ERROR\n");
                                return -1;
                            }

                            if (entry.inode.setTargetBlock(entry.seekPtr, (short) freeBlock) != 0) {
                                SysLib.cerr("WRITE ERROR\n");
                                return -1;
                            }
                            // No errors, continue
                        default:
                            targetBlock = freeBlock;
                            break;
                    }
                }

                // read until targetBlock into the buffer
                byte[] targetBlockBuffer = new byte[512];

                if (SysLib.rawread(targetBlock, targetBlockBuffer) == -1) {
                    return -1;
                }
                // Find position in block
                int byteInBlock = entry.seekPtr % 512;
                int blockRemaining = 512 - byteInBlock;

                // Determine the maximum amount that can be written in this iteration
                int maxCanBeWritten = (blockRemaining > bufferRemaining) ? bufferRemaining:blockRemaining;
                // copy to main buffer
                System.arraycopy(buffer, bytesWritten, targetBlockBuffer, byteInBlock, maxCanBeWritten);
                // write to block
                SysLib.rawwrite(targetBlock, targetBlockBuffer);

                // update counts and pointers
                bytesWritten += maxCanBeWritten;
                entry.seekPtr += maxCanBeWritten;
                bufferRemaining -= maxCanBeWritten;
                if (entry.seekPtr > entry.inode.length) {
                    entry.inode.length = entry.seekPtr;
                }
            }

            // sync up the file with the disk and return the number of bytes written
            entry.inode.toDisk(entry.iNumber);
            return bytesWritten;
        }
    }


    private boolean deallocAllBlocks(FileTableEntry entry) {
        return entry.inode.deallocateAllBlocks(entry.iNumber);
    }

    public boolean freeBlock(int blockNumber) {
        return superBlock.freeBlock(blockNumber);
    }

    public boolean delete(String fileName) {
        FileTableEntry entry = open(fileName, "w");
        short inumber = entry.iNumber;
        boolean closeSuccess = close(entry);
        boolean ifreeSuccess = directory.ifree(inumber);
        return closeSuccess && ifreeSuccess;
    }


    // Seek is used to update the seekptr depending on the parameters passed
    public int seek(FileTableEntry entry, int offset, int whence) {
        synchronized (entry) {
            int fileSize = fsize(entry);
            switch (whence) {
                // set seek to offset into the block
                case SEEK_SET:
                    if (offset <= fileSize && offset >= 0) entry.seekPtr = offset;
                    else return -1;
                    break;
                // set seek to offset from current seek
                case SEEK_CUR:
                    if (entry.seekPtr + offset >= 0 && entry.seekPtr + offset <= fileSize)
                        entry.seekPtr = entry.seekPtr + offset;
                    else return -1;
                    break;
                // Set seek to offset from the end of the file
                case SEEK_END:
                    if (offset > 0 || fileSize + offset < 0) return -1;
                    entry.seekPtr = fileSize + offset;
            }
            return entry.seekPtr;
        }
    }
}
























































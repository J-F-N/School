/*/////////////////////////////////////
Edited by: Parker Amundsen
Last Edit: 03/13/2020
Description: Superblock maintains general data of the file system such as the
number of blocks, the number of Inodes, and a pointer to the next free block.
The free block is the first block available for storage of data. Additional
functionality includes formatting the number of files the system supports,
storing data to disk, returning a pointer to the next free block, and
freeing up a block by moving it's data to disk and pointing to it as the
next free block.
 */////////////////////////////////////

public class SuperBlock {
    public int totalBlocks;
    public int inodeBlocks;
    public int freeList;
    private final int defaultMaxFiles = 64;


    // Constructor that initializes the superblock to handle size number of blocks
    public SuperBlock(int size) {
        byte[] buffer = new byte[512];
        SysLib.rawread(0, buffer);
        totalBlocks = SysLib.bytes2int(buffer, 0);
        inodeBlocks = SysLib.bytes2int(buffer, 4);
        freeList = SysLib.bytes2int(buffer, 8);

        if (size != totalBlocks || freeList < 2 || inodeBlocks <= 0) {
            totalBlocks = size;
            SysLib.cerr("Formatting to a Maximum of 64 files");
            format(defaultMaxFiles);
        }
    }

    // Formats the disk in a way that supports the number of files given.
    public void format(int files) {
        inodeBlocks = files;

        // Initialize inodes
        for (short inodeBlockIndex = 0; inodeBlockIndex < inodeBlocks; inodeBlockIndex++) {
            Inode file = new Inode();
            file.flag = 0;
            file.toDisk(inodeBlockIndex);
        }

        this.freeList = 2 + this.inodeBlocks * Inode.iNodeSize / 512;
        // Chain the free blocks together by writing the next free block number to the first two bytes.
        for (int blocks = freeList; blocks < totalBlocks; blocks++) {
            byte[] buffer = new byte[512];

            for (int blockByte = 0; blockByte < 512; blockByte++) {
                buffer[blockByte] = 0;
            }
            SysLib.int2bytes(blocks + 1, buffer, 0);
            SysLib.rawwrite(blocks, buffer);
        }
        toDisk();
    }

    // Synchronizes the current Superblock attributes with saved Superblock attributes on the disk.
    void toDisk() {
        byte[] buffer = new byte[512];
        SysLib.int2bytes(this.totalBlocks, buffer, 0);
        SysLib.int2bytes(this.inodeBlocks, buffer, 4);
        SysLib.int2bytes(this.freeList, buffer, 8);
        SysLib.rawwrite(0, buffer);
        SysLib.cerr("Superblock synchronized\n");
    }



    // Returns the free block and update the freeList to the next free block
    // after reading from first two bytes of block
    public int getFreeBlock() {
        int pointer = freeList;
        if (pointer != -1) {
            byte[] buffer = new byte[512];
            SysLib.rawread(pointer, buffer);
            freeList = SysLib.bytes2int(buffer, 0);
            SysLib.int2bytes(0, buffer, 0);
            SysLib.rawwrite(pointer, buffer);
        }
        return pointer;
    }

    // Clears out the block specified in parameter assigning all bits to 0
    // Assigns current freeList to blockNumber and writes old freeList to
    // the first 2 bytes of the blockNumber
    // Returns true if successful
    public boolean freeBlock(int blockNumber) {

        if (blockNumber < 0 || blockNumber > totalBlocks) {
            return false;
        } else {
            byte[] buffer = new byte[512];

            for(int byteInBlock = 0; byteInBlock < 512; byteInBlock++) {
                buffer[byteInBlock] = 0;
            }
            SysLib.int2bytes(freeList, buffer, 0);
            SysLib.rawwrite(blockNumber, buffer);
            freeList = blockNumber;
            return true;
        }
    }
}
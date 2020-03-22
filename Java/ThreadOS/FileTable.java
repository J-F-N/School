/*/////////////////////////////////////
Edited by: John Neigel
Last Edit: 03/13/2020
Description: FileTable contains a vector of FileTableEntry. Each FileTableEntry is
a currently open file. The modes of an open file may be "r"(read), "w"(write), "w+"(read/write),
and "a"(append). The FileTable allows multiple threads to read from a given file at a time,
but not while there is already a writer. Additionally, there can only be one "w", "w+", or "a", at a time.
This is to prevent desynchronization of the file data. A wait notify pattern is used to coordinate threads.
 */////////////////////////////////////

import java.io.File;
import java.util.Vector;

public class FileTable {

    private Directory directory;
    private Vector<FileTableEntry> fileTable;

    public FileTable(Directory directory) {
        this.directory = directory;
        fileTable = new Vector<FileTableEntry>();
    }

    //allocate a new file table entry for this file
    //allocate/retrieve and register the corresponding inode using directory
    //increment this inode's count
    //immediately write back this inode to the disk
    //return a reference to this file tale entry
    public synchronized FileTableEntry falloc(String fileName, String mode) {
        Inode iNode = null;
        short iNumber;

        //if directory create new Inode
        if (fileName.equals("/"))
            iNumber = 0;

            //then get iNumber of the Inode under that filename
        else
            iNumber = directory.namei(fileName);

        //get Inode data associated with iNumber
        if (iNumber >= 0)
            iNode = new Inode(iNumber);

        while (true) {

            //make sure we can add a reader
            if (mode.equals("r")) {
                //check for file before read, return null if not present in table
                if (iNumber == -1)
                    return null;

                //if it's unused or being read, okay to add another reader
                if (iNode.flag == Inode.UNUSED || iNode.flag == Inode.READ) {
                    break;
                }

                //check for writer, wait if true
                else if (iNode.flag == Inode.WRITE) {
                    try {
                        wait();
                    } catch (InterruptedException ie) {
                    }
                }
            }

            //mode must be w, w+, or a
            else {
                //if file does not exist or was deleted, allocate new iNode for this file
                if (iNumber < 0 || iNode.flag == Inode.DELETED) {
                    iNumber = directory.ialloc(fileName);
                    iNode = new Inode();
                    iNode.flag = Inode.UNUSED;
                }

                //no current readers or writers, okay to write
                if (iNode.flag == Inode.UNUSED) {
                    break;
                }

                //there must be a reader or writer, wait
                else {
                    try {
                        wait();
                    } catch (InterruptedException ie) {
                    }
                }
            }
        }

        iNode.count++;
        iNode.toDisk(iNumber);
        FileTableEntry ftEnt = new FileTableEntry(iNode, iNumber, mode);
        fileTable.addElement(ftEnt);

        return ftEnt;
    }

    //locate passed param for FileTableEntry
    //store corresponding Inode state to disk
    //remove entry from FileTable
    //return false if entry is not in the table
    public synchronized boolean ffree(FileTableEntry entry) {
        if (fileTable.removeElement(entry)) {
            entry.inode.count--;
            entry.inode.toDisk(entry.iNumber);
            entry = null;
            notify();
            return true;
        } else
            return false;
    }

    //returns a boolean
    // true if fileTable is empty, false otherwise
    public synchronized boolean fempty() {
        return fileTable.isEmpty();
    }
}

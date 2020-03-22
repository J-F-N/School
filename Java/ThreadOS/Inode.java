/*/////////////////////////////////////
Edited by: Sneha Ravichandran
Last Edit: 03/14/2020
Description: The Inode contains all the needed metadata of each FileTableEntry currently pointing it it.
Each Inode is associated with a file and tracks the number of threads using it by way of count.
The Inode's flag identifies the mode of the currently open file, and direct/indirect pointers are stored
to indentify the block where file data can be found in the file system. Constants are present to
drive clarity of the method operations in the FileTable.java and to allow additional file modes to be added
or updated in this location. The default constructor is used to create new Inodes for new files. The parameterized
constructor is used to retreive the state of an Inode from the disk.
 */////////////////////////////////////

public class Inode {
    public final static int iNodeSize = 32;       // fix to 32 bytes
    public final static int directSize = 11;      // # direct pointers

    public int length;                             // file size in bytes
    public short count;                            // # file-table entries pointing to this
    public short flag;                             // 0 = unused, 1 = used, ...
    public short direct[] = new short[directSize]; // direct pointers
    public short indirect;                         // a indirect pointer

    //ERROR CODES
    public static final int NoError = 0;
    public static final int ErrorBlockRegistered = -1;
    public static final int ErrorPrecBlockUnused = -2;
    public static final int ErrorIndirectNull = -3;

    //constants for use in FileTable
    public static final short UNUSED = 0;
    public static final short READ = 1;
    public static final short WRITE = 2;
    public static final short DELETED = 3;


    //a default constructor
    Inode() {
        this.length = 0;
        this.count = 0;
        this.flag = 1;
        for ( int i = 0; i < directSize; i++ ){
          this.direct[i] = -1;
        }
        this.indirect = -1;
    }

    //retrieving inode from disk
    Inode( short iNumber ) {
      int blockNum = 1 + iNumber / 16;
      byte[] buf = new byte[512];
      SysLib.rawread(blockNum, buf);

      int d = (iNumber % 16) * iNodeSize; //offset
      this.length = SysLib.bytes2int(buf, d);
      d += 4;
      this.count = SysLib.bytes2short(buf, d);
      d += 2;
      this.flag = SysLib.bytes2short(buf, d);
      d += 2;

      for(int i = 0; i < 11; ++i) {
          this.direct[i] = SysLib.bytes2short(buf, d);
          d += 2;
      }

      this.indirect = SysLib.bytes2short(buf, d);
    }

     //save to disk as the i-th inode
     //ensures data is stable over reboot of ThreadOS
//     void toDisk(short iNumber) {
//         byte[] buf = new byte[iNodeSize];
//         byte byteOffset = 0;
//         SysLib.int2bytes(this.length, buf, byteOffset);
//         int offset = byteOffset + 4; //offset
//         SysLib.short2bytes(this.count, buf, offset);
//         offset += 2;
//         SysLib.short2bytes(this.flag, buf, offset);
//         offset += 2;
//
//         int i;
//         for(i = 0; i < 11; ++i) {
//             SysLib.short2bytes(this.direct[i], buf, offset);
//             offset += 2;
//         }
//
//         SysLib.short2bytes(this.indirect, buf, offset);
//         i = 1 + iNumber / 16;
//         byte[] bigBuf = new byte[512];
//         SysLib.rawread(i, bigBuf);
//         offset = iNumber % 16 * 32;
//         System.arraycopy(buf, 0, bigBuf, offset, 32);
//         SysLib.rawwrite(i, bigBuf);
//     }

    void toDisk(short var1) {
        byte[] var2 = new byte[32];
        byte var3 = 0;
        SysLib.int2bytes(this.length, var2, var3);
        int var6 = var3 + 4;
        SysLib.short2bytes(this.count, var2, var6);
        var6 += 2;
        SysLib.short2bytes(this.flag, var2, var6);
        var6 += 2;

        int var4;
        for(var4 = 0; var4 < 11; ++var4) {
            SysLib.short2bytes(this.direct[var4], var2, var6);
            var6 += 2;
        }

        SysLib.short2bytes(this.indirect, var2, var6);
        var6 += 2;
        var4 = 1 + var1 / 16;
        byte[] var5 = new byte[512];
        SysLib.rawread(var4, var5);
        var6 = var1 % 16 * 32;
        System.arraycopy(var2, 0, var5, var6, 32);
        SysLib.rawwrite(var4, var5);
    }


    //sets the indirect block value to the value of iNumber if valid
    boolean setIndexBlock(short iNumber ) {
      //check the blocks to see if they're valid
      for(int i = 0; i < 11; ++i) {
          if (this.direct[i] == -1) {
              return false;
          }
      }

      //make sure that there's a valid indirect block index
      if (this.indirect != -1) {
          return false;
      } else {
          this.indirect = iNumber;
          byte[] buf = new byte[512];

          for(int j = 0; j < 256; ++j) {
              SysLib.short2bytes((short)-1, buf, j * 2);
          }

          SysLib.rawwrite(iNumber, buf);
          return true;
      }
    }

    //finds the block with the number in params (iNumber)
    public int getTargetBlock(int iNumber ) {
      int targetNum = iNumber / 512;
      if (targetNum < 11) {
          return this.direct[targetNum];
      } else if (this.indirect < 0) {
          //error indirect block dne
          return this.ErrorBlockRegistered;
      } else {
          byte[] buf = new byte[512];
          SysLib.rawread(this.indirect, buf);
          int blockNum = targetNum - 11;
          return SysLib.bytes2short(buf, blockNum * 2);
      }
    }

    //sets the target block using the position and blockValue of the target block
    public int setTargetBlock(int position, short d) {
      int targetNum = position / 512;
      if (targetNum < 11) {
          if (this.direct[targetNum] >= 0) {
              //error block is already registered
              return this.ErrorBlockRegistered;
          } else if (targetNum > 0 && this.direct[targetNum - 1] == -1) {
              //error prec block is unused
              return this.ErrorPrecBlockUnused;
          } else {
              this.direct[targetNum] = d;
              return this.NoError;
          }
      } else if (this.indirect < 0) {
          //error the indirect is not valid
          return this.ErrorIndirectNull;
      } else {
          byte[] buf = new byte[512];
          SysLib.rawread(this.indirect, buf);
          int blockNum = targetNum - 11;
          //error message
          if (SysLib.bytes2short(buf, blockNum * 2) > 0) {
              SysLib.cerr("indexBlock, indirectNumber = " + blockNum);
              return this.ErrorBlockRegistered;
          } else {
              SysLib.short2bytes(d, buf, blockNum * 2);
              SysLib.rawwrite(this.indirect, buf);
              return this.NoError;
          }
      }
    }

    //frees the indirect block
    public byte[] freeIndirectBlocks() {
        if (this.indirect >= 0) {
            byte[] buf = new byte[512];
            SysLib.rawread(this.indirect, buf);
            this.indirect = -1;
            return buf;
        } else {
            return null;
        }
    }

    // Deallocates all of the blocks associated with this Inode if there is only one
    // entry in the filetable
    public boolean deallocateAllBlocks(short iNumber) {
        if (count != 1) return false;

        // get the index block
        byte[] indexBlockData = freeIndirectBlocks();
        if (indexBlockData != null) {
            byte blockByte = 0;
            short block;

            // Free evey block used in the index block
            while((block = SysLib.bytes2short(indexBlockData, blockByte)) != -1) {
                Kernel.fs.freeBlock(block);
            }
        }

        int directBlockIndex = 0;

        // Free every direct block associated with this inode
        while(true) {
            if (directBlockIndex >= 11) {
                toDisk(iNumber);
                return true;
            }
            if (direct[directBlockIndex] != -1) {
                Kernel.fs.freeBlock(direct[directBlockIndex]);
                direct[directBlockIndex] = -1;
            }

            directBlockIndex++;
        }
    }

}

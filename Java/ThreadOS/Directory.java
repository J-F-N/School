/*/////////////////////////////////////
Edited by: John Neigel
Last Edit: 03/15/2020
Description: Directory contains the data for files stored in ThreadOS and their associated Inodes
It uses two arrays. One for the size of the file name and one two-dimensional array
for the file names themselves. The index number of fsize where a particular file
is found is the iNumber of the associated Inode. Directory also contains methods to
convert to and from byte code. This is used sync data with the disc.
 */////////////////////////////////////

public class Directory {
    private static int nameSize = 30;
    private int[] fsize;
    private char[][] fnames;


    public Directory(int maxInodes)
    {
        fsize = new int[maxInodes];

        //initialize all file slots to 0
        for (int i = 0; i < maxInodes; i++)
            fsize[i] = 0;

        fnames = new char[maxInodes][nameSize];

        //name and assign root directory
        String root = "/";
        fsize[0] = root.length();
        root.getChars(0, fsize[0], fnames[0], 0);
    }

    //converts byte array from disk to proper Directory array form
    public void bytes2Directory(byte data[])
    {
        //keeps track of copy position in data[]
        int startIndex = 0;

        //convert bytes 4 at a time since each int is 4 bytes
        //insert into each index of array
        //using helper function from Syslib
        for (int i = 0; i < fsize.length; i++)
        {
            fsize[i] = SysLib.bytes2int(data, startIndex);
            startIndex += 4;
        }

        //get file names from byte arr
        //starting index changes by nameSize * 2
        //since each char can hold 2 bytes
        for (int i = 0; i < fnames.length; i++)
        {
            String name = new String(data, startIndex, nameSize * 2);
            name.getChars(0, fsize[i], fnames[i], 0);
            startIndex += nameSize * 2;
        }
    }

    //converts directory array data into byte array to be stored on disk
    public byte[] directory2Bytes()
    {
        //initialize byte array big enough to hold all ints and chars from arrays
        byte[] byteArr = new byte[fnames.length * nameSize * 2 + fsize.length * 4];

        //keeps track of insertion position in byteArr[]
        int startIndex = 0;

        //convert into the bytes 4 at a time
        for (int i = 0; i < fsize.length; i++)
        {
            SysLib.int2bytes(fsize[i], byteArr, startIndex);
            startIndex += 4;
        }

        //convert fnames to byte array, then add sub array to byteArr
        for (int i = 0; i < fsize.length; i++)
        {
            String temp = new String(fnames[i], 0, fsize[i]);
            byte[] subArr = temp.getBytes();
            System.arraycopy(subArr, 0, byteArr, startIndex, subArr.length);
            startIndex += nameSize * 2;
        }

        return byteArr;
    }

    //allocates an Inode for a new file to be opened
    //searches the fsize for an index with value '0'
    //if there are no Inodes available return -1
    public short ialloc(String filename)
    {
        for(short i = 1; i < fsize.length; i++)
        {
            if(fsize[i] == 0)
            {
                //take smaller of two, preventing fsize too big
                fsize[i] = Math.min(nameSize, filename.length());
                filename.getChars(0, fsize[i], fnames[i], 0);
                return i;
            }
        }

        return -1;
    }

    //if Inode with iNumber is currently in directory remove it, return true
    //else if not present in directory, return false
    //loops through fnames to clear out file name
    public boolean ifree(short iNumber)
    {
        if(fsize[iNumber] != 0)
        {
            fsize[iNumber] = 0;

            for(int i = 0; i < fnames[iNumber].length; i++)
            {
                fnames[iNumber][i] = '\0';

                if(fnames[iNumber + 1] == null)
                    break;
            }

            return true;
        }

        else
            return false;
    }

    //returns the inumber of the inode associated with the param fileName
    //check size first, then if match, check name for equality
    //returns -1 if no inode is found
    public short namei(String fileName)
    {
        for(short i = 1; i < fsize.length; i++)
        {
            if(fsize[i] == fileName.length())
            {
                if(new String(fnames[i], 0, fsize[i]).equals(fileName))
                    return i;
            }
        }

        return -1;
    }
}
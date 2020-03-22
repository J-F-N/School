/*////////////////////////////////////
Edited by: John Neigel
Last Edit: 03/15/2020
Description: This driver, along with RTest.java check for file creation and retrieval
over a reboot of ThreadOS. This Test and RTest.java should be run from ThreadOS, not from the Shell.
This is because the loader.class command 'q' can only be executed from the ThreadOS command prompt.
This is necessary because once 'q' is entered, ThreadOS performs a sync to the disk.
//////////////////////////////////////

Instructions to Test
1. Start ThreadOS with 'java Boot'
2. Enter into the prompt 'l CTest'
3. Upon completion of test enter 'q'.
4. After ThreadOS is shut down, reboot with 'java Boot'
5. Enter into the prompt 'l RTest'.
6. The file created by CTest should then be successfully loaded
by RTest.
 */

public class CTest extends Thread {

    final static int DEFAULTFILES = 48;
    final int files;
    int fd;
    final byte[] buf16 = new byte[16];
    final byte[] buf32 = new byte[32];
    final byte[] buf24 = new byte[24];
    int size;

    public CTest( String args[] ) {
        files = Integer.parseInt( args[0] );
        // SysLib.cout( "files = " + files + "\n" );
    }

    public CTest() {
        files = DEFAULTFILES;
        // SysLib.cout( "files = " + files + "\n" );
    }

    public void run()
    {
        if ( test1( ) ) // format with specified # of files
            SysLib.cout("Correct behavior of format......................2\n");
        if ( test2( ) ) // open "TestFile" with "w+"
            SysLib.cout("Correct behavior of open........................2\n");
        if ( test3( ) ) // write buf[16]
            SysLib.cout("Correct behavior of writing a few bytes.........2\n");
        if ( test4( ) ) // close fd
        {
            SysLib.cout("Correct behavior of close.......................2\n");
            SysLib.cout("Now enter 'q' into the prompt. After ThreadOS stops, \n" +
                           "reboot with 'java Boot' and enter 'l RTest\n");
        }

        SysLib.exit( );
    }

    private boolean test1( ) {
        //.............................................."
        SysLib.cout( "1: format( " + files + " )..................." );
        SysLib.format( files );
        byte[] superblock = new byte[512];
        SysLib.rawread( 0, superblock );
        int totalBlocks = SysLib.bytes2int( superblock, 0 );
        int inodeBlocks = SysLib.bytes2int( superblock, 4 );
        int freeList = SysLib.bytes2int( superblock, 8 );
        if ( totalBlocks != 1000 ) {
            SysLib.cout( "totalBlocks = " + totalBlocks + " (wrong)\n" );
            return false;
        }
        if ( inodeBlocks != files && inodeBlocks != files / 16 ) {
            SysLib.cout( "inodeBlocks = " + inodeBlocks + " (wrong)\n" );
            return false;
        }
        if ( freeList != 1 + files / 16 && freeList != 1 + files / 16 + 1 ) {
            SysLib.cout( "freeList = " + freeList + " (wrong)\n" );
            return false;
        }
        SysLib.cout( "successfully completed\n" );
        return true;
    }

    private boolean test2( ) {
        //.............................................."
        SysLib.cout( "2: fd = open( \"TestFile\", \"w+\" )...." );
        fd = SysLib.open( "TestFile", "w+" );
        if ( fd != 3 ) {
            SysLib.cout( "fd = " + fd + " (wrong)\n" );
            return false;
        }
        SysLib.cout( "successfully completed\n" );
        return true;
    }

    private boolean test3( ) {
        //.............................................."
        SysLib.cout( "3: size = write( fd, buf[16] )...." );
        for ( byte i = 0; i < 16; i++ )
            buf16[i] = i;
        size = SysLib.write( fd, buf16 );
        if ( size != 16 ) {
            SysLib.cout( "size = " + size + " (wrong)\n" );
            return false;
        }
        SysLib.cout( "successfully completed\n" );
        return true;
    }

    private boolean test4( ) {
        //.............................................."
        SysLib.cout( "4: close( fd )...................." );
        SysLib.close( fd );

        size = SysLib.write( fd, buf16 );
        if ( size > 0 ) {
            SysLib.cout( "writable even after closing the file\n" );
            return false;
        }

        SysLib.cout( "successfully completed\n" );
        return true;
    }
}

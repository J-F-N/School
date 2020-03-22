/*////////////////////////////////////
Edited by: John Neigel
Last Edit: 03/15/2020
Description: This driver looks in the filesystem for the file "TestFile". If found, returns success
message. Run and follow instructions for CTest before running this test.
 *///////////////////////////////////////

public class RTest extends Thread{

    final static int DEFAULTFILES = 48;
    final int files;
    int fd;
    final byte[] buf16 = new byte[16];
    final byte[] buf32 = new byte[32];
    final byte[] buf24 = new byte[24];
    int size;

    public RTest( String args[] ) {
        files = Integer.parseInt( args[0] );
        // SysLib.cout( "files = " + files + "\n" );
    }

    public RTest() {
        files = DEFAULTFILES;
        // SysLib.cout( "files = " + files + "\n" );
    }

    public void run()
    {
        if ( test5( ) ) // read buf[16] from "TestFile"
        {
            SysLib.cout("Correct behavior of reading a few bytes.........2\n");
            SysLib.cout("We just read the bytes created and stored from CTest....\n");
        }

        SysLib.exit();
    }

    private boolean test5( ) {
        //.............................................."
        SysLib.cout( "5: reopen and read from \"TestFile\".." );
        for ( byte i = 0; i < 16; i++ )
            buf16[i] = i;

        fd = SysLib.open( "TestFile", "r" );

        byte[] tmpBuf = new byte[16];
        size = SysLib.read( fd, tmpBuf );
        if ( size != 16 ) {
            SysLib.cout( "size = " + size + " (wrong)\n" );
            SysLib.close( fd );
            return false;
        }
        for ( int i = 0; i < 16; i++ )
            if ( tmpBuf[i] != buf16[i] ) {
                SysLib.cout( "buf[" + i + "] = " + tmpBuf[i] + " (wrong)\n" );
                SysLib.close( fd );
                return false;
            }
        SysLib.close( fd );
        SysLib.cout( "successfully completed\n" );
        return true;
    }

}

import java.io.* ;
public class RandomAccess {
	public static void main(String args[]) throws IOException
	{
		// write primitive data in binary format to the "mydata" file
		RandomAccessFile myfile = new RandomAccessFile( "input.txt", "rw");
		myfile.writeInt(120);
		myfile.writeDouble(375.50);
		myfile.writeInt('A'+ 1);
		myfile.writeBoolean(true);
		myfile.writeChar('X');
		// set pointer to the beginning of file and read next two items
		myfile.seek(0);
		System.out.println(myfile.readInt());
		System.out.println(myfile.readDouble());
		// set pointer to the 4th item and read it
		myfile.seek(16);
		System.out.println(myfile.readBoolean());
		myfile.seek(myfile.length());
		myfile.writeInt(2003);
		// read 5th and 6th items
		myfile.seek(17);
		System.out.println(myfile.readChar());
		System.out.println(myfile.readInt());
		System.out.println( "File length: "+ myfile.length());
		myfile.close();
	}
}

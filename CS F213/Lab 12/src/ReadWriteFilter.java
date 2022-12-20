import java.io.*;
public class ReadWriteFilter
{
	public static void main(String args[]) throws IOException
	{
		// write primitive data in binary format to the file
		FileOutputStream fos = new FileOutputStream( "input.txt");
		DataOutputStream dos = new DataOutputStream(fos);
		dos.writeInt(120);
		dos.writeDouble(375.50);
		dos.writeInt('A'+ 1);
		dos.writeBoolean(true);
		dos.writeChar('X');
		dos.close();
		fos.close();
		// read primitive data in binary format from the file
		FileInputStream fis = new FileInputStream( "input.txt");
		DataInputStream dis = new DataInputStream(fis);
		System.out.println(dis.readInt());
		System.out.println(dis.readDouble());
		System.out.println(dis.readInt());
		System.out.println(dis.readBoolean());
		System.out.println(dis.readChar());
		dis.close();
		fis.close();
	}
}
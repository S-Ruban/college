import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
public class exercise_3
{
	public static void main(String[] args) throws IOException
	{
		DataInputStream dos = new DataInputStream(new FileInputStream("input.txt"));
		System.out.println(dos.readInt() + " " + dos.readDouble());
	}
}
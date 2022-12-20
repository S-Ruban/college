import java.io.* ;
import java.util.* ;
public class StudentRecord
{
	public static void main(String args[]) throws IOException
	{
		// Create buffered reader for standard input
		BufferedReader dis = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// reading data from console
		System.out.print("Enter Student Details: ");
		st = new StringTokenizer(dis.readLine());// HCS15004 Siva 35
		int stdID = Integer.parseInt(st.nextToken());
		String stdName = st.nextToken();
		int stdMarks = Integer.parseInt(st.nextToken());
		// write to console
		System.out.println("Student details are:");
		System.out.println("ID: "+ stdID);
		System.out.println("Name: "+ stdName);
		System.out.println("Marks: "+ stdMarks);
	}
}
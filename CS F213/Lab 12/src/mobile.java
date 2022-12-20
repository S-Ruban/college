import java.io.FileOutputStream;	// importing library required to output data from to file
import java.io.IOException;	// to automatically catch any exception during runtime
import java.util.Scanner;
import java.util.regex.Pattern;	// to import regex functionalities to validate name and phone number
public class mobile
{
	public static void main(String[] args) throws IOException
	{
		FileOutputStream fos = new FileOutputStream("mobile.txt");	// open file output stream to read data to the file or creates file if it does not already exist
		Scanner sc = new Scanner(System.in);
		String name, number ;
		while(true)	// as long as input is valid, enter invalid input to exit
		{
			System.out.print("Enter name: ");
			name = sc.nextLine();
			System.out.print("Enter mobile number: ");
			number = sc.nextLine();
			if((Pattern.matches("[a-zA-z\s]+", name)) && (Pattern.matches("[0-9]{10}", number)))	// using regex to validate name and phone number
			{
				String data = name + "-" + number + "\n" ;	// preparing data to be written into the file
				fos.write(data.getBytes());	// first converting it to a byte array and then writing it into the textfile
			}
			else
				break ;	// will exit program
		}
		fos.close();	// closing the stream to avoid any file I/O error
	}
}
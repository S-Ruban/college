import java.util.Scanner ;
class InvalidCharException extends Exception // exception class
{
	public InvalidCharException()
	{
		super("Error in Input"); // output message
	}
}
public class CharInp
{
	public static void main(String[] args) throws InvalidCharException // to throw the exception
	{
		Scanner sc = new Scanner(System.in);
		int c = 1 ; // counter of the number of valid characters entered
		while(true) // infinite loop to accept input as long as its only ONE letter or digit must be input
		{
			String str = sc.nextLine();
			if((Character.isLetterOrDigit(str.charAt(0))) && (str.length() == 1)) // only ONE letter or digit must be input
				System.out.println("No. of chars:" + (c++)); // print count of number of characters entered so far
			else
				throw new InvalidCharException(); // manually throw the exception
		}
	}
}
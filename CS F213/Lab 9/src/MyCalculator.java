import java.util.InputMismatchException;
import java.util.Scanner ;
class NegativeException extends Exception // exception class to handle if both inputs are negative
{
	public NegativeException()
	{
		super("java.lang.Exception: n or p should not be negative."); // output message
	}
}
class ZeroException extends Exception // exception class to handle if both inputs are zero
{
	public ZeroException()
	{
		super("java.lang.Exception: n and p should not be zero."); // output message
	}
}
public class MyCalculator
{
	static long power(int a, int b) // function to calculate a^b by binary exponentiation
	{
		if(b == 0)
			return 1 ;
		else if(b % 2 == 0)
			return power(a, b/2)*power(a, b/2);
		else
			return a*power(a, b/2)*power(a, b/2);
	}
	public static void main(String[] args) throws NegativeException, ZeroException // to throw both exceptions
	{
		Scanner sc = new Scanner(System.in);
		try
		{
			int n = sc.nextInt();
			int p = sc.nextInt();
			if((n < 0) || (p < 0))
				throw new NegativeException(); // manually throw NegativeException
			else if((n == 0) && (p == 0))
				throw new ZeroException();  // manually throw ZeroException
			else
				System.out.println(power(n, p));
		}
		catch(NegativeException | ZeroException nze)  // catching NegativeException or ZeroException using pipe operator
		{
			System.out.println(nze.getMessage()); //printing output message
		}
		catch(InputMismatchException ime) // incase the input is not an integer
		{
			System.out.println("Please enter only integers.");
			main(args); // running program from beginning
		}
	}
}
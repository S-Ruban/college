class NotPositiveException extends Exception
{
// constructors
public NotPositiveException()
{
super("Error: Not a positive number"); // call to one argument
 }
public NotPositiveException (String s)
{
super(s); // call to one argument constructor of Exception
}
}

public class exercise_3
{
	void addItemsToCart(int q)
	{
		try
		{
			if(q <= 0)
				throw new NotPositiveException ("Not positive: " + q);
			else
				System.out.println("Correct data: " + q);
		}
		catch(NotPositiveException npe)
		{
			System.out.println(npe.getMessage());
		}
	}
}
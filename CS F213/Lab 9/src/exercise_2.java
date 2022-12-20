import java.util.Scanner ;
public class exercise_2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		try
		{
			System.out.println(X/Y);
		}
		catch (ArithmeticException ae)
		{
			System.out.println(ae);
		}
		finally
		{
			System.out.println("End of Program");
		}
	}
}
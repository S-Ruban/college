import java.util.Scanner ;
public class exercise_4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		try
		{
			int x = Integer.parseInt(sc.nextLine());
		}
		catch(NumberFormatException nfe)
		{
			System.out.println("Please enter an integer only.");
			main(args);
		}
	}
}
import java.util.Scanner ;
public class problem_3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two strings : ");
		String x = sc.nextLine();
		String y = sc.nextLine();
		if(x.length() != y.length())
			System.out.println( (x.length() > y.length()) ? x + " is larger": y + " is larger");
		else
			System.out.println("Strings are of equal length.");
	}
}
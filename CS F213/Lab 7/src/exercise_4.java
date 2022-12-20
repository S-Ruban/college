import java.util.Scanner ;
import java.util.regex.* ;
public class exercise_4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a username : ");
		String user = sc.nextLine();
		System.out.print(user + " is ");
		if(!Pattern.matches("[a-zA-z][\\w]{2,19}", user))
			System.out.print("not ");
		System.out.println("a valid username.");
	}
}
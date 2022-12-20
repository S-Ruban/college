import java.util.Scanner ;
public class exercise_4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a 4-digit number : ");
		int num = sc.nextInt();
		int rev = 0, temp = num ;
		while(temp != 0)
		{
			rev = rev*10 + (temp%10);
			temp /= 10 ;
		}
		System.out.println("The reverse of " + num + " is " + rev);
	}
}
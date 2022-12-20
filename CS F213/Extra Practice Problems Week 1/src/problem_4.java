import java.util.Scanner ; 
public class problem_4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two integers : ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		System.out.print(a + " is ");
		if(a % b != 0)
			System.out.print("not ");
		System.out.print("a multiple of " + b);
	}
}
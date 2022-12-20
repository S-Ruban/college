import java.util.Scanner ; 
public class problem_1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter three integers : ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		System.out.println(a + " × " + b + " × " + c + " = " + a*b*c);
	}
}
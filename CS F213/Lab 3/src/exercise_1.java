import java.util.Scanner ;
public class exercise_1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length and breadth of the rectange : ");
		System.out.println( sc.nextDouble() == sc.nextDouble() ? "It is a square." : "It is not a square" );
	}
}
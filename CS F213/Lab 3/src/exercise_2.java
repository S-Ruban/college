import java.util.Scanner ;
public class exercise_2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter three numbers : ");
		int x = sc.nextInt();
		int y = sc.nextInt();
		int z = sc.nextInt();
		if((x == y) && (x == z))
			System.out.println("The three numbers are equal.");
		else
		{
			if(x > y)
			{
				if(x > z)
					System.out.println(x + " is the largest integer.");
				else
					System.out.println(z + " is the largest integer.");
			}
			else
			{
				if(y > z)
					System.out.println(y + " is the largest integer.");
				else
					System.out.println(z + " is the largest integer.");
			}
		}
	}
}
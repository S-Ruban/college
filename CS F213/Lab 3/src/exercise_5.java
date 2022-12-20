import java.util.Scanner ;
public class exercise_5
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a year : ");
		int y = sc.nextInt();
		System.out.print(y + " is");
		if(y % 4 == 0)
		{
			if(y % 100 == 0)
			{
				if(y % 400 != 0)
					System.out.print(" not");
			}
		}
		else
			System.out.print(" not");
		System.out.println(" a leap year.");
	}
}
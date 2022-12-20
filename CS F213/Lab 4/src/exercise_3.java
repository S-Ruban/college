import java.util.Scanner ;
public class exercise_3
{
	static int fact(int x)
	{
		if(x == 0)
			return 1 ;
		else
			return x*fact(x-1);
	}
	static void pascal(int x)
	{
		if(x == 1)
			System.out.println(1);
		else
		{
			System.out.print(" ");
			pascal(x-1);
			for(int r = 0; r <= x; r++)
				System.out.print((fact(x)/(fact(x-r)*fact(r))) + " ");
			System.out.println();
		}
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Input number of rows: ");
		int n = sc.nextInt();
		pascal(n-1);
	}
}
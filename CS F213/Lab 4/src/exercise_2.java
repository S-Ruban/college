import java.util.Scanner ;
public class exercise_2
{
	static int fact(int n)
	{
		if(n == 0)
			return 1 ;
		else
			return n*fact(n-1);
	}
	static double pow(double a, int b)
	{
		if(b == 0)
			return 1 ;
		else
			return a*pow(a, b-1);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter x : ");
		double x = sc.nextDouble();
		double res = 0 ;
		for(int i = 0; i < 10; i++)
			res += pow(x, i)/fact(i);
		System.out.println("e^" + x + " = " + res);
	}
}
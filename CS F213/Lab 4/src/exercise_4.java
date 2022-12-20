import java.util.Scanner; ;
public class exercise_4
{
	static int hcf(int x, int y)
	{
		if(x > y)
		{
			if(x % y == 0)
				return y ;
			else
				return hcf(x%y, y);
		}
		else
		{
			if(y % x == 0)
				return x ;
			else
				return hcf(x, y%x);
		}
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a fraction : ");
		String frac = sc.nextLine();
		int a = Integer.parseInt(frac.substring(0, frac.indexOf('/')));
		int b = Integer.parseInt(frac.substring(frac.indexOf('/')+1, frac.length()));
		System.out.println(frac + " = " + (a/hcf(a,b)) + "/" + (b/hcf(a,b)));
	}
}
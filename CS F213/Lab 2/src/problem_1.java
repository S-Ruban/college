import java.util.Scanner ; 

class plus
{
	plus(int x, int y)
	{
		System.out.println(x + " + " + y + " = " + (x+y));
	}
}

class minus
{
	minus(int x, int y)
	{
		System.out.println(x + " - " + y + " = " + (x-y));
	}
}

class multiply
{
	multiply(int x, int y)
	{
		System.out.println(x + " × " + y + " = " + (x*y));
	}
}

class divide
{
	divide(int x, int y)
	{
		System.out.println(x + " ÷ " + y + " = " + ((double)x/(double)y));
	}
}

public class problem_1 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two numbers : ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		plus p = new plus(a, b);
		minus m = new minus(a, b);
		multiply mp = new multiply(a, b);
		divide d = new divide(a, b);
	}
}
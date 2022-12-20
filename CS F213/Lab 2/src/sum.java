/* I am aware that my code looks complex, however, it accomplishes what has been asked in the questions while
 * using constructors and constructor overloading. I have use the bitwise and operator (&) to check if a number is
 * odd or even. The sum of first n odd numbers is n^2 and the sum of first n even numbers is n*(n+1)
 * n+(n&1) will give the next even number if n is odd and give n itself when n is even*/
import java.util.Scanner ;
public class sum 
{
	sum(int x)
	{
		for(int i = 2-(x&1); i < x; i += 2) // using '&' to check if odd or even
			System.out.print(i+"+");
		System.out.println(x + "="+(((x+(x&1))*(x+(x&1)))/4 + ((1-(x&1))*(x/2)))); 
	}
	sum(int x, int y)
	{
		for(int i = 2-(x&1); i < x; i += 2)
			System.out.print("("+i+"*"+y+")+");
		System.out.print("("+x+"*"+y+")");
		System.out.print("=");
		for(int i = 2-(x&1); i < x; i += 2)
			System.out.print(i*y+"+");
		System.out.println(x*y+"="+y*(((x+(x&1))*(x+(x&1)))/4 + ((1-(x&1))*(x/2))));
	}
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two numbers (enter any other character if you want to input only one number) : ");
		int a = sc.nextInt();
		if(sc.hasNextInt()) //hasNextInt() to check if the next input token is an integer or not
		{
			int b = sc.nextInt();
			sum s2 = new sum(a,b);
		}
		else
		{
			sum s1 = new sum(a);
		}
	}
}
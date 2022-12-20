import java.util.Scanner ;
public class tiles
{
	static int log2(int x)
	{
		return (int)(Math.log10(x)/Math.log10(2)); // log2(x) = log10(x)/log10(2)
	}
	static int pow(int a, int b)  // my own power function using recursion because at times, due to rounding error, Math.pow() gives wrong answer
	{
		if(b == 0)
			return 1 ;
		if(b % 2 == 0)
			return pow(a, b/2)*pow(a, b/2);
		else
			return a*pow(a, b/2)*pow(a, b/2);
	}
	static int solve(int r, int c) // to solve an area of dimensions r x c
	{
		if(r >= c)
		{
			if(c == 1) // just one row of squares
			{
				System.out.println("solve(" + r + "," + c + ") = " + r);
				System.out.print(r + " tile");
				if(r != 1)
					System.out.print("s"); // don't mind this, just some English grammar
				System.out.println(" of 1×1.");
				return r ; // returns the number of 1 x r tiles
			}
			else if(c == 0)
			{
				System.out.println("solve(" + r + "," + c + ") = 0");
				return 0 ; // cause no tiles, obviously
			}
			else
			{
				int s = log2(Math.min(r, c)), tr = r/pow(2,s), tc = c/pow(2,s); // 2^s is the side of the largest tile possible, tr is the number of squares per column of side 2^s, tc is the number of squares per row of side 2^s
				System.out.println("solve(" + r + "," + c + ") = " + tr + "*" + tc + " + solve(" + (r-tr*pow(2,s)) + "," + pow(2,s) + ") + solve(" + (c-tc*pow(2,s)) + "," + r + ")");
				System.out.print(tr*tc + " tile");
				if(tr*tc != 1)
					System.out.print("s"); // don't mind this, just some English grammar
				System.out.print(" of " + pow(2,s) + "×" + pow(2,s) + ", ");
				return (tr*tc + solve((r-tr*pow(2,s)), pow(2,s)) + solve((c-tc*pow(2,s)), r)); // split the total area into three parts; the area tiled, and two rectangles that are untiled, then recursively solve the rectangles
				// Below line is same as above line, just without the intermediate variables, hence will look confusing
				//return ((r/pow(2,(log2(Math.min(r, c)))))*(c/pow(2,(log2(Math.min(r, c))))) + solve((r-(r/pow(2,(log2(Math.min(r, c)))))*pow(2,(log2(Math.min(r, c))))), pow(2,(log2(Math.min(r, c))))) + solve((c-( c/pow(2,(log2(Math.min(r, c)))))*pow(2,(log2(Math.min(r, c))))), r));
			}
		}
		return solve(c,r) ; // if c > r, i just flip c and r, to use the above code
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the values of N and M : ");
		int N = sc.nextInt();
		int M = sc.nextInt();
		System.out.println("Area of " + N + "×" + M + " tiles can be covered with minimum "+ solve(N, M) + " tile(s).");
	}
}
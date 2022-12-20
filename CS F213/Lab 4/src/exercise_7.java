import java.util.Scanner ;
public class exercise_7
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Input the number: ");
		int n = sc.nextInt();
		for(int i = 0; i < (2*n-1)*(2*n-1)+(2*n-1); i++)
		{
			/*
			int r = i/(2*n)+1;    row number (goes from 1,2,3,...,2n-1
			int c = i % (2*n);    column number (goes from 0,1,2,..., 2n-1)
			if(c <= Math.abs(n-r))     leaves n-1 spaces in line 1, n-2 spaces in line 2, ..., 0 space in line n, 1 space in line n+1, 2 spaces in line n+2, ..., n-1 spaces in line 2n-1
				System.out.print(" ");
			else if((c >= Math.abs(n-r)) && (c <= Math.abs(n-r)+(2*n-1)-2*Math.abs(n-r)))    1 number in line 1, 3 numbers in line 2, 5 numbers in line 3, ..., 2n-1 numbers in line n, 2n-3 numbers in line n+1, ..., 1 number in line 2n-1
				System.out.print(Math.abs(n-c)+1);    since column centre is n, take |n-c|, then add 1
			else
				System.out.print(" ");    print spaces on other side
			if(c == 2*n-1)    if at the end of a line, go to next line
				System.out.println();
			*/
			if((i % (2*n)) <= Math.abs(n-(i/(2*n)+1)))
				System.out.print(" ");
			else if(((i % (2*n)) >= Math.abs(n-(i/(2*n)+1))) && ((i % (2*n)) <= Math.abs(n-(i/(2*n)+1))+(2*n-1)-2*Math.abs(n-(i/(2*n)+1))))
				System.out.print(Math.abs(n-(i % (2*n)))+1);
			else
				System.out.print(" ");
			if((i % (2*n)) == 2*n-1)
				System.out.println();
		}
	}
}
import java.util.Scanner ;
public class problem_5
{
	public static void main(String[] args)
	{
		int num, l = -2147483648, c = 1 ;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter 10 numbers : ");
		while(c <= 10)
		{
			num = sc.nextInt();
			if(num > l)
				l = num ;
			c++ ;
		}
		System.out.println("The largest number is " + l);
	}
}
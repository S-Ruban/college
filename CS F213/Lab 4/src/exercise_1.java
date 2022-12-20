import java.util.Scanner ;
public class exercise_1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int i = 0, prod = 1 ;
		double avg = 0 ;
		String n ;
		do
		{
			n = sc.nextLine();
			if(n.equalsIgnoreCase("q"))
				break ;
			else
			{
				i++ ;
				avg += Integer.parseInt(n);
				prod *= Integer.parseInt(n);
			}
		} while(true);
		avg /= i ;
		System.out.println("Average of the numbers entered = " + avg);
		System.out.println("Product of the numbers entered = " + prod);
	}
}
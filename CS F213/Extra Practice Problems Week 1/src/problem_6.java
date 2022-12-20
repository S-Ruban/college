import java.util.Scanner ;
public class problem_6
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number : ");
		String num = sc.next();
		int f ;
		for(char ch = '0'; ch <= '9'; ch++)
		{
			f = 0 ;
			for(int i = 0; i < num.length(); i++)
			{
				if(num.charAt(i) == ch)
					f++ ;
			}
			if(f > 1)
				System.out.println("Repeated digit : " + ch + "    Frequency : " + f);
		}
		System.out.println("First digit : " + num.charAt(0));
		System.out.println("Last digit : " + num.charAt(num.length()-1));
	}
}
import java.util.Scanner ;
public class exercise_6
{
	static Boolean isprime(int x)
	{
		if(x == 2)
			return true ;
		if(x % 2 == 1)
		{
			for(int i = 3; i*i <= x; i += 2)
			{
				if(x % i == 0)
					return false ;
			}
			return true ;
		}
		else
			return false ;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number : ");
		int n = sc.nextInt();
		System.out.print("The prime factors of " + n + " are : ");
		if(isprime(n))
			System.out.println(n);
		else
		{
			if(n % 2 == 0)
			{
				System.out.print("2 ");
				if(isprime(n/2) && (n%4 == 2))
					System.out.print(n/2 + " ");
			}
			for(int i = 3; i*i <= n; i++)
			{
				if((n%i == 0) && (isprime(i)))
				{
					System.out.print(i + " ");
					if(isprime(n/i))
						System.out.print(n/i + " ");
				}
			}
		}
	}
}
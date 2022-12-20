import java.util.Scanner ;
public class hourglass
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int j ;
		for(int i = 1; i <= 2*N-1; i++)
		{
			if(i <= N)
			{
				for(j = 0; j <= 2*(i-1); j++)
					System.out.print(" ");
				for(j = N+1-i; j > 0; j--)
					System.out.print(j + " ");
				for(j = 2; j <= N+1-i; j++)
					System.out.print(j + " ");
				for(j = 0; j <= 2*(i-1); j++)
					System.out.print(" ");
			}
			else
			{
				for(j = 0; j <= 2*(2*N-1-i); j++)
					System.out.print(" ");
				for(j = i-N+1; j > 0; j--)
					System.out.print(j + " ");
				for(j = 2; j <= i-N+1; j++)
					System.out.print(j + " ");
				for(j = 0; j <= 2*(2*N-1-i); j++)
					System.out.print(" ");
			}
			System.out.println();
		}
		// below code achieves the same task in same time complexity, but only one loop
		/*
		for(int i = 0; i < (4*N-3)*(2*N-1); i++)
		{
			//int r = i/(4*N-3)+1 ;
			//int c = i % (4*N-3);
			if(((i % (4*N-3)) < 2*(N-1-Math.abs((i/(4*N-3)+1)-N))))
				System.out.print(" ");
			else if(((i % (4*N-3)) >= 2*(N-1-Math.abs((i/(4*N-3)+1)-N))) && ((i % (4*N-3)) <= 2*(N-1+Math.abs((i/(4*N-3)+1)-N))))
			{
				if((Math.abs(2*(N-1)-(i % (4*N-3)))+1) % 2 == 1)
					System.out.print(((Math.abs(2*(N-1)-(i % (4*N-3)))+1)+1)/2 + " ");
			}
			else
				System.out.print(" ");
			if((i % (4*N-3)) == 4*N-4)
				System.out.println();
		
		}
		*/
	}
}
public class exercise_8 
{
	public static void main(String [] args)
	{
		int n = 6 ;
		for(int i = 0; i < n*(4*n-3); i++)
		{
			if((i % (4*n-3)) >= 2*(n-(i / (4*n-3) + 1)))
			{
				if((i % (4*n-3)) >= 2*(n+(i / (4*n-3) + 1))-3)
					System.out.print(" ");
				else
				{
					if(((i % (4*n-3))-(2*(n-(i / (4*n-3) + 1)))) % 4 == 0)
						System.out.print("*");
					else
						System.out.print(" ");
				}
			}
			else 
				System.out.print(" ");
			if((i % (4*n-3)) == 4*n-4)
				System.out.println();
		}
	}
}
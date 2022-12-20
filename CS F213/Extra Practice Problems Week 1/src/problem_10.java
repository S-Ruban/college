import java.util.Scanner ;
public class problem_10
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the first sentence : ");
		String str1 = sc.nextLine();
		String [] w1 = str1.split(" ");
		System.out.print("Enter the second sentence : ");
		String str2 = sc.nextLine();
		String [] w2 = str2.split(" ");
		System.out.print("The common words from both the sentences are : ");
		for(int x = 0; x < w1.length; x++)
		{
			for(int y = 0; y < w2.length; y++)
			{
				if(w1[x].equalsIgnoreCase(w2[y]))
					System.out.print(w1[x] + " ");
			}
		}
	}
}
import java.util.Scanner;
import java.lang.StringBuffer ;
public class problem_9
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a sentence : ");
		String str = sc.nextLine();
		String [] words = str.split(" ");
		System.out.print("The palindromic words in the sentence are : ");
		for(int i = 0; i < words.length; i++)
		{
			StringBuffer sb = new StringBuffer(words[i]);
			sb.reverse();
			if(words[i].equalsIgnoreCase(sb.toString()))
				System.out.print(words[i] + " ");
		}
	}
}
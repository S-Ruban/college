import java.util.Scanner ;
public class problem_8
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a sentence : ");
		String str = sc.nextLine();
		System.out.print("Enter a number : ");
		int n = sc.nextInt();
		String [] words = str.split(" ");
		System.out.println(words[n-1].toUpperCase());
	}
}
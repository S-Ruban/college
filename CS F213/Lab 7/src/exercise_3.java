import java.util.Scanner ;
public class exercise_3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		System.out.print("Alphabets in string: ");
		for(int i = 0; i < str.length(); i++)
		{
			if(Character.isAlphabetic(str.charAt(i)))
				System.out.print(str.charAt(i));
		}
		System.out.println();
		System.out.print("Numbers in string: ");
		for(int i = 0; i < str.length(); i++)
		{
			if(Character.isDigit(str.charAt(i)))
				System.out.print(str.charAt(i));
		}
	}
}
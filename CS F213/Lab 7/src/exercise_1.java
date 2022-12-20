import java.util.Scanner ;
public class exercise_1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two strings : ");
		String str1 = sc.nextLine();
		String str2 = sc.nextLine();
		int a[][] = new int[2][26];
		for(int i = 0; i < 26; i++)
		{
			a[0][i] = 0 ;
			a[1][i] = 0 ;
		}
		for(char ch = 'a'; ch <= 'z'; ch++)
		{
			for(int i = 0; i < str1.length(); i++)
			{
				if(str1.charAt(i) == ch)
					a[0][(int)ch-97]++ ;
			}
			for(int i = 0; i < str2.length(); i++)
			{
				if(str2.charAt(i) == ch)
					a[1][(int)ch-97]++ ;
			}
		}
		for(int i = 0; i < 26; i++)
		{
			if(a[0][i] != a[1][i])
			{
				System.out.println(str1 + " and " + str2 + " are not anagrams.");
				System.exit(0);
			}
		}
		System.out.println(str1 + " and " + str2 + " are anagrams.");
	}
}
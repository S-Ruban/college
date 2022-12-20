import java.util.Scanner ;
public class exercise_2
{
	static boolean iscircular(String x, String y)
	{
		int e  = 0 ;
		for(int i = 0; i < x.length(); i++)
		{
			if(y.indexOf(x.substring(0,i)) != -1)
				e = i ;
		}
		//System.out.println(e);
		//String ss1 = str1.substring(0,e), ss2 = str1.substring(e), ss3 = str2.substring(0,str2.length()-e), ss4 = str2.substring(str2.length()-e);
		//System.out.println(ss1 + " " + ss2 + "\n" + ss3 + " " + ss4);
		//if((ss1.equalsIgnoreCase(ss4)) && (ss2.equalsIgnoreCase(ss3)))
		if(((x.substring(0,e)).equalsIgnoreCase(y.substring(y.length()-e))) && ((x.substring(e)).equalsIgnoreCase(y.substring(0,y.length()-e))))
			return true ;
		else
			return false ;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two strings : ");
		String str1 = sc.nextLine();
		String str2 = sc.nextLine();
		if(iscircular(str1, str2))
			System.out.println("True");
		else
			System.out.println("False");
	}
}
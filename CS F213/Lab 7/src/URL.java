import java.util.Scanner ;
import java.util.StringTokenizer ;
public class URL
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("URL : ");
		StringTokenizer url = new StringTokenizer(sc.nextLine(), ":/");
		if(url.hasMoreTokens())
			System.out.println(url.nextToken() + " is the protocol identifier");
		if(url.hasMoreTokens())
			System.out.println(url.nextToken() + " is the domain name");
		if(url.hasMoreTokens())
		{
			String port = url.nextToken();
			System.out.print(port + " is the ");
			try
			{
				int x = Integer.parseInt(port);
				System.out.print("port ");
			}
			catch(NumberFormatException nfe) // incase there is no port name mentioned
			{
				System.out.print("resource name.");
				System.exit(0);
			}
			System.out.println("name");
		}
		if(url.hasMoreTokens())
			System.out.println(url.nextToken() + " is the resource name.");
	}
}
import java.util.Scanner ;
public class temp
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Input Fahrenheit value ");
		System.out.println("Equivalent Celsius value " + 5*(sc.nextDouble()-32)/9);
	}
}
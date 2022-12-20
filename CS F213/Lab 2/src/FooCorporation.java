import java.util.Scanner ;
public class FooCorporation
{
	static void pay(float bp, int h)
	{
		if(bp < 8.00)
			System.out.println("Wages too low!");
		else if(h > 60)
			System.out.println("Worker too stressed out!");
		else
			System.out.printf("Wages for this employee is : $%.2f", bp*Math.min(h, 40)+bp*Math.max(0, h-40)*1.5);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the base pay for the employee : ");
		float base = sc.nextFloat();
		System.out.print("Enter the number of hours the employee worked : ");
		int hour = sc.nextInt();
		pay(base, hour);
	}
}
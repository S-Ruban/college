import java.util.Scanner ;
public class revenue
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter unit price: ");
		float price = sc.nextFloat();
		System.out.print("Enter quantity: ");
		int qty = sc.nextInt();
		System.out.printf("Revenue before discount: $%.2f\n", price*qty);
		if(qty >= 100)
		{
			if(qty > 120)
			{
				System.out.printf("Discounted amount (15%%): $%.2f\n", price*qty*0.15d);
				System.out.printf("The revenue from the sale after discount : $%.2f", price*qty*0.85d);
			}
			else
			{
				System.out.printf("Discounted amount (10%%): $%.2f\n", price*qty*0.1d);
				System.out.printf("The revenue from the sale after discount : $%.2f", price*qty*0.9d);
			}
		}
		else
		{
			System.out.println("Discounted amount (0%): $0.00");
			System.out.printf("The revenue from the sale after discount : $%.2f", price*qty);
		}	
	}
}
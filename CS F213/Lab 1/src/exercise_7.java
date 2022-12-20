import java.util.Scanner ;
public class exercise_7 
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter your name : ");
		String name = sc.nextLine();
		System.out.print("Enter your house number : ");
		String hn = sc.nextLine();
		System.out.print("Enter the street you live in : ");
		String street = sc.nextLine();
		System.out.print("Enter the state you live in : ");
		String state = sc.nextLine();
		System.out.print("Enter the pincode of your area : ");
		int pin = sc.nextInt();
		System.out.println("Name: " + name);
		System.out.println("House Number: " + hn);
		System.out.println("Street: " + street);
		System.out.println("State: " + state);
		System.out.println("Pincode: " + pin);
	}
}
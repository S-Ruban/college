import java.util.Scanner ;
class Taxi extends Automobile
{
	private String CarID ;
	private double totalDistance ;
	void calcdist()
	{
		name();
		totalDistance = FuelTankCapacity * mileage ;
	}
	void name()
	{
		CarID = model + Integer.toString(plateNumber);
	}
	void showdist()
	{
		System.out.println("Car Id: " + CarID);
		System.out.println("Total distance: " + totalDistance);
	}
}
public class Automobile
{
	String model ;
	int plateNumber ;
	double FuelTankCapacity, mileage ;
	Scanner sc = new Scanner(System.in);
	void input()
	{
		System.out.print("Model: ");
		model = sc.nextLine();
		System.out.print("Plate Number: ");
		plateNumber = sc.nextInt();
		System.out.print("Fuel Tank Capacity: ");
		FuelTankCapacity = sc.nextDouble();
		System.out.print("Mileage: ");
		mileage = sc.nextDouble();
	}
	public static void main(String[] args)
	{
		Taxi t = new Taxi();
		t.input();
		t.calcdist();
		t.showdist();
	}
}
import java.util.Scanner;
public class length
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Input a value for inch: ");
		double inch = sc.nextDouble();
		System.out.println(inch + " inch is " + inch*0.0254 + " meters");
	}
}
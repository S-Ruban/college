import java.util.Scanner ;
public class BMI
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter your weight (in kg) : ");
		float weight = sc.nextFloat();
		System.out.print("Enter your height (in m) : ");
		float height = sc.nextFloat();
		System.out.println("BMI : " + weight/(height*height));
		System.out.print("BMI Category : ");
		if((weight/(height*height)) < 15.0d)
			System.out.println("Starvation");
		else if(((weight/(height*height)) >= 15.0d) && ((weight/(height*height)) < 17.5d))
			System.out.println("Anorexic");
		else if(((weight/(height*height)) >= 17.5d) && ((weight/(height*height)) < 18.5d))
			System.out.println("Underweight");
		else if(((weight/(height*height)) >= 18.5d) && ((weight/(height*height)) < 25.0d))
			System.out.println("Ideal");
		else if(((weight/(height*height)) >= 25.0d) && ((weight/(height*height)) < 30.0d))
			System.out.println("Overweight");
		else if(((weight/(height*height)) >= 30.0d) && ((weight/(height*height)) < 40.0d))
			System.out.println("Obese");
		else if((weight/(height*height)) > 40.0d)
			System.out.println("Morbidly Obese");
	}
}
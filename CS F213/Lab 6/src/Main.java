import java.util.Scanner ;
interface Shape
{
	void Text();
}
class TextConvert implements Shape
{
	String str ;
	public void Text()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter string: ");
		str = sc.nextLine();
		str = Character.toUpperCase(str.charAt(0)) + str.substring(1);
	}
}
class Circle extends TextConvert
{
	double radius ;
	void fitsText()
	{
		if((str.length()-2*radius) < 0)
			System.out.println("Text is sufficient in circle");
		else
			System.out.println("Text is not sufficient in circle");
	}
}
class Rectangle extends TextConvert
{
	double length ;
	void fitsText()
	{
		if((str.length()-this.length) < 0)
			System.out.println("Text is sufficient in Rectangle");
		else
			System.out.println("Text is not sufficient in Rectangle");
	}
}
public class Main
{
	public static void main(String [] args)
	{
		Circle c = new Circle();
		Rectangle r = new Rectangle();
		c.Text();
		Scanner sc = new Scanner(System.in);
		System.out.print("Radius of a circle: ");
		c.radius = sc.nextDouble();
		System.out.print("Length of a rectangle: ");
		r.length = sc.nextDouble();
		System.out.println("Converted Text: " + c.str);
		System.out.println("Length of a text: " + c.str.length());
		System.out.println("Diameter of a circle=" + 2*c.radius);
		r.str = c.str ;
		c.fitsText();
		r.fitsText();
	}
}
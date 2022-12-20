import java.util.Scanner ;
class Circle extends shape
{
	private double radius ;
	Circle(double r)
	{
		radius = r ;
	}
	void display()
	{
		System.out.println("Area of a Circle: " + Math.PI*radius*radius);
	}
}
class Rectangle extends shape
{
	private double length, breadth ;
	Rectangle(double l, double b)
	{
		length = l ;
		breadth = b ;
	}
	void display()
	{
		System.out.println("Area of a Rectangle: " + length*breadth);
	}
}
class Triangle extends shape
{
	double base, height ;
	Triangle(double b, double h)
	{
		base = b ;
		height = h ;
	}
	void display()
	{
		System.out.println("Area of a Triangle: " + 0.5*base*height);
	}
}
public class shape
{
	void display()
	{
		System.out.println("shape");
	}
	public static void main(String [] args)
	{
		shape s = new shape();
		s.display();
		Scanner sc = new Scanner(System.in);
		System.out.println("1.	Circle\r\n" + 
				"2.	Rectangle\r\n" + 
				"3.	Triangle");
		System.out.print("Choose the number to which you want to calculate the area: ");
		int ch = sc.nextInt();
		switch(ch)
		{
			case 1 :
				System.out.print("Enter Radius: ");
				Circle c = new Circle(sc.nextDouble());
				c.display();
				break ;
			case 2 :
				System.out.print("Enter length: ");
				double ln = sc.nextDouble();
				System.out.print("Enter breadth: ");
				double br = sc.nextDouble();
				Rectangle r = new Rectangle(ln, br);
				r.display();
				break ;
			case 3 :
				System.out.print("Enter base: ");
				double ba = sc.nextDouble();
				System.out.print("Enter height: ");
				double hgt = sc.nextDouble();
				Triangle t = new Triangle(ba, hgt);
				t.display();
			default :
				System.out.println("\nPlease enter a valud choice.\n");
				main(args);
		}
	}
}
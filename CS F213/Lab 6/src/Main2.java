import java.util.Scanner ;
interface movableObject
{
	abstract void moveUp();
	abstract void moveDown();
	abstract void moveLeft();
	abstract void moveRight();
}
abstract class movablePoint implements movableObject
{
	double x, y, dx, dy ;
	movablePoint(double a, double b, double c, double d)
	{
		x = a ;
		y = b ;
		dx = c ;
		dy = d ;
	}
}
class movableRectangle extends movablePoint
{
	movableRectangle(double a, double b, double c, double d)
	{
		super(a, b, c, d);
	}
	movablePoint bottomLeft, topRight ;
	public void moveUp()
	{
		bottomLeft.moveUp();
		topRight.moveUp();
	}
	public void moveDown()
	{
		bottomLeft.moveDown();
		topRight.moveDown();
	}
	public void moveRight()
	{
		bottomLeft.moveRight();
		topRight.moveRight();
	}
	public void moveLeft()
	{
		bottomLeft.moveLeft();
		topRight.moveLeft();
	}
}
public class Main2
{
	public static void main(String[] args)
	{
		double x1, x2, y1, y2, dx, dy ;
		Scanner sc = new Scanner(System.in);
		System.out.print("x1=");
		x1 = sc.nextDouble();
		System.out.print("x2=");
		x2 = sc.nextDouble();
		System.out.print("y1=");
		y1 = sc.nextDouble();
		System.out.print("y2=");
		y2 = sc.nextDouble();
		System.out.print("dx=");
		dx = sc.nextDouble();
		System.out.print("dy=");
		dy = sc.nextDouble();
		movableRectangle mr = new movableRectangle(0,0,0,0);
		mr.bottomLeft = new movablePoint(x1,y1,dx,dy)
		{
			public void moveUp() { y += dy ; }
			public void moveDown() { y -= dy ; }
			public void moveRight() { x += dx ; }
			public void moveLeft() {x -= dx ; }
		};
		mr.topRight = new movablePoint(x2,y2,dx,dy)
		{
			public void moveUp() { y += dy ; }
			public void moveDown() { y -= dy ; }
			public void moveRight() { x += dx ; }
			public void moveLeft() {x -= dx ; }
		};
		System.out.println("moveUp()");
		System.out.print("y1=" + mr.bottomLeft.y + "+" + mr.bottomLeft.dy + "=");
		mr.bottomLeft.moveUp();
		System.out.println(mr.bottomLeft.y);
		System.out.print("y2=" + mr.topRight.y + "+" + mr.topRight.dy + "=");
		mr.topRight.moveUp();
		System.out.println(mr.topRight.y);
		mr.bottomLeft.moveDown(); // reset point
		mr.topRight.moveDown(); // reset point
		System.out.println("moveLeft()");
		System.out.print("x1=" + mr.bottomLeft.x + "-" + mr.bottomLeft.dx + "=");
		mr.bottomLeft.moveLeft();
		System.out.println(mr.bottomLeft.x);
		System.out.print("x2=" + mr.topRight.x + "-" + mr.topRight.dx + "=");
		mr.topRight.moveLeft();
		System.out.println(mr.topRight.x);
		mr.bottomLeft.moveRight(); // reset point
		mr.topRight.moveRight(); // reset point
		System.out.println("moveDown()");
		System.out.print("y1=" + mr.bottomLeft.y + "-" + mr.bottomLeft.dy + "=");
		mr.bottomLeft.moveDown();
		System.out.println(mr.bottomLeft.y);
		System.out.print("y2=" + mr.topRight.y + "-" + mr.topRight.dy + "=");
		mr.topRight.moveDown();
		System.out.println(mr.topRight.y);
		mr.bottomLeft.moveUp(); // reset point
		mr.topRight.moveUp(); // reset point
		System.out.println("moveRight()");
		System.out.print("x1=" + mr.bottomLeft.x + "+" + mr.bottomLeft.dx + "=");
		mr.bottomLeft.moveRight();
		System.out.println(mr.bottomLeft.x);
		System.out.print("x2=" + mr.topRight.x + "+" + mr.topRight.dx + "=");
		mr.topRight.moveRight();
		System.out.println(mr.topRight.x);
		mr.bottomLeft.moveLeft(); // reset point
		mr.topRight.moveLeft(); // reset point
	}
}
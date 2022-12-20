public class Rectangle
{
	int l, b ;
	Rectangle(int length, int breadth)
	{
		l = length ;
		b = breadth ;
	}
	int area(int x, int y)
	{
		return x*y ;
	}
	int perimeter(int x, int y)
	{
		return 2*(x+y);
	}
}
import java.applet.Applet ;
import java.awt.Color;
import java.awt.Graphics;
public class Rainbow7 extends Applet
{
	public void paint(Graphics g)  
    {
		setBackground(Color.black); // making background black
		Color c [] = {Color.red, Color.orange, Color.yellow, Color.green, Color.cyan, Color.blue, Color.magenta, Color.black}; //storing all colours to be used
		for(int i = 0; i < c.length; i++) // loop to access all colours
		{
			g.setColor(c[i]); // set the colour to be painted
			g.fillOval(50+6*i, 50+6*i, 332-12*i, 236-12*i); // fill the ovals such that it converges to the centre (I had to take a screenshot of the picture in the labsheet and open it in MS Paint to determine the size in pizels)
		}
    } 
}
import java.awt.Button;	// importing button feature of Java AWT
import java.awt.Checkbox;	// importing radio button feature of Java AWT
import java.awt.CheckboxGroup;	// importing radio button features feature of Java AWT
import java.awt.Choice;		// importing drop-down list feature of Java AWT
import java.awt.Color;	// importing colors of Java AWT
import java.awt.Frame;	// importing frame feature of Java AWT
import java.awt.Label;	// importing label feature of Java AWT
import java.awt.TextArea;	// importing multi-line text-box feature of Java AWT
import java.awt.TextField;	// importing single-line text-box feature of Java AWT
import java.awt.event.ActionEvent;	// importing action-receiving feature of Java AWT
import java.awt.event.ActionListener;	// importing action-processing feature of Java AWT
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class studreg extends Frame implements ActionListener
{
	Frame f = new Frame();	// creating a new Java AWT Frame object
	Label head = new Label("Student Registration");
	Label l1 = new Label("Name:");
	TextField tf1 = new TextField();	// creating text field to input name
	Label l2 = new Label("Age:");
	Choice c1 = new Choice();	// creating drop-down list to input age
	Label l3 = new Label("Sex(M/F):");
	CheckboxGroup cbg1 = new CheckboxGroup(); 	// creating radio buttons to input sex
	Checkbox male = new Checkbox("Male", cbg1, false);
	Checkbox fem = new Checkbox("Female", cbg1, false);
	Label l4 = new Label("Address:");
	TextArea ta = new TextArea();	// creating text box to input area
	Label l5 = new Label("Course:");
	Choice c2 = new Choice();	// creating drop-down list to input course (branch)
	String [] courses = {"B.E. Chemical", "B.E. Civil", "B.E. Electrical & Electronics", "B.E. Mechanical", "B.Pharm", "B.E. Computer Science", "B.E. Electronics and Instrumentation", "B.E. Electronics and Communication", "M.Sc. Biological Sciences", "M.Sc. Chemistry", "M.Sc. Economics", "M.Sc. Mathematics", "M.Sc. Physics"};
	// above line has list of all courses offered for undergraduate students in BITS Pilani, Hyderabad Campus
	Label l6 = new Label("Semester:");
	Choice c3 = new Choice();	// creating drop-down list to input semester
	Button save = new Button("save");
	
	studreg()
	{  
		f.setSize(870, 552);	// setting size of the frame
		f.setBackground(Color.cyan);	// setting background colour of the frame
		f.setLayout(null);
		f.setVisible(true);	// making the frame visible
		
		head.setBounds(195, 52, 137, 13);
		f.add(head);
		
		l1.setBounds(51, 80, 36, 13);
		f.add(l1);
		
		tf1.setBounds(213, 77, 188, 20);
		f.add(tf1);
		
		l2.setBounds(51, 109, 27, 13);
		f.add(l2);
		
		c1.setBounds(213, 103, 83, 21);
		for(int i = 16; i < 27; i++)
			c1.add(Integer.toString(i));	// adding age options in drop-down list
		f.add(c1);
		
		l3.setBounds(51, 138, 72, 13);
		f.add(l3);
		
		male.setBounds(212, 138, 71, 13);
		f.add(male);
		fem.setBounds(302, 138, 95, 13);
		f.add(fem);
		
		l4.setBounds(51, 208, 63, 13);
		f.add(l4);
		
		ta.setBounds(214, 208, 187, 62);
		f.add(ta);
		
		l5.setBounds(51, 291, 54, 13);
		f.add(l5);
		
		c2.setBounds(213, 291, 300, 13);
		for(int i = 0; i < courses.length; i++)
			c2.add(courses[i]);	// adding course options in drop-down list
		f.add(c2);
		
		l6.setBounds(51, 322, 72, 13);
		f.add(l6);
		
		c3.setBounds(213, 322, 83, 21);
		for(int i = 1; i < 12; i++)
			c3.add(Integer.toString(i));	// adding semester options in drop-down list
		f.add(c3);
		
		save.setBounds(211, 383, 85, 33);
		f.add(save);
		save.addActionListener(this); // capturing button-click event
		
		f.addWindowListener(new WindowAdapter() {
		      public void windowClosing(WindowEvent
		      windowEvent) {
		        System.exit(0);
		      }
		    });
		// above block of code is to terminate the execution if the close button is clicked
	}  
	public void actionPerformed(ActionEvent e)
	{
		Label conf = new Label("Student details Saved!");
		conf.setBounds(348, 480, 198, 13);
		conf.setForeground(Color.red);	// setting text of label to red
		f.add(conf);
	}  
	public static void main(String args[])
	{  
		new studreg();	// instantiating the framework
	}  
} 
class Student
{
	String name;
	String course;
	int age;
	void displayInfo ()
	{
		System.out.println ("Student Information");
		System.out.println ("Name: "+name);
		System.out.println ("Course: "+course);
		System.out.println ("Age: "+age);
	}
}
class Student_Info
{
	public static void main (String args[])
	{
		Student stud1 = new Student();
		// assigning values to the objects
		stud1.name = "Ravi";
		stud1.course = "Java";
		stud1.age = 23;
		stud1.displayInfo();
	}
}
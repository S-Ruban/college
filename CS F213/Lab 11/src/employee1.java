import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class employee1
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException // to deal with any exceptions while connecting to database
	{
		Scanner sc = new Scanner(System.in);
		Class.forName("com.mysql.jdbc.Driver"); // loading the JDBC driver
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS"); // connecting to the database
		Statement s = (Statement) con.createStatement(); // to execute SQL statements to access/modify the table in the database
		String create = "CREATE TABLE `test`.`employee` (\r\n" + 
				"  `id` INT NOT NULL AUTO_INCREMENT,\r\n" + 
				"  `name` VARCHAR(45) NOT NULL,\r\n" + 
				"  `designation` VARCHAR(45) NOT NULL,\r\n" + 
				"  `salary` INT NOT NULL,\r\n" + 
				"  PRIMARY KEY (`id`),\r\n" + 
				"  UNIQUE INDEX `id_UNIQUE` (`id` ASC) VISIBLE,\r\n" + 
				"  UNIQUE INDEX `name_UNIQUE` (`name` ASC) VISIBLE);" ;
		// above string is SQL query to create table employee
		s.executeUpdate(create); // to execute above SQL query
		System.out.println("Enter the number of employees");
		int n = sc.nextInt();
		System.out.println("\n");
		String name, desig ; // to input names and designation to add to the table
		int sal ; // to input salary to add to the table
		for(int i = 1; i <= n; i++)
		{
			System.out.println("Employee " + i);
			System.out.print("Name: ");
			sc.nextLine();
			name = sc.nextLine();
			System.out.print("Designation: ");
			desig = sc.nextLine();
			System.out.print("Salary: ");
			sal = sc.nextInt();
			String data = "INSERT INTO employee \r\n" + 
					"VALUES (" + Integer.toString(i) + ", '" + name + "', '" + desig + "', " + Integer.toString(sal) + ");" ;
			// above string is SQL query to insert data into the table
			s.executeUpdate(data); // to execute above SQL query
			System.out.println("\n");
		}
		ResultSet rs = s.executeQuery("SELECT * FROM employee"); // SQL query to view the table
		int index = 0, hs = 0 ; // to store index and highest salary
		while(rs.next()) // linear search through the table to find highest salary
		{
			if(rs.getInt("id") == 1)
			{
				index = 1 ;
				hs = rs.getInt("salary");
			}
			else
			{
				if(rs.getInt("salary") > hs)
				{
					index = rs.getInt("id");
					hs = rs.getInt("salary");
				}
			}
		}
		rs.absolute(index); // setting cursor to the record with highest salary
		System.out.println("Maximum salary Employee:");
		System.out.println("Name: " + rs.getString("name"));
		System.out.println("Designation: " + rs.getString("designation"));
		System.out.println("Salary: " + rs.getInt("salary"));
	}
}
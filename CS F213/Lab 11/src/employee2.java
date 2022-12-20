import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class employee2
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException // to deal with any exceptions while connecting to database
	{
		Scanner sc = new Scanner(System.in);
		Class.forName("com.mysql.jdbc.Driver"); // loading the JDBC driver
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS"); // connecting to the database
		Statement s = (Statement) con.createStatement(); // to execute SQL statements to access/modify the table in the database
		System.out.println("Please enter ID and password");
		System.out.print("ID: ");
		int id = sc.nextInt();
		System.out.print("Password: ");
		sc.nextLine();
		String pwd = sc.nextLine();
		boolean flag = true ;
		ResultSet rs = s.executeQuery("SELECT * FROM employee2"); // SQL query to view the table
		while(rs.next())
		{
			if(id == rs.getInt("id")) // checking if ID exists
			{
				if(pwd.equals(rs.getString("password"))) // checking if password matches to ID
				{
					DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
					System.out.println("\n\nPlease find below your payslip\n");
					System.out.println("Date: " + LocalDate.now().format(formatter));
					System.out.println("Name: " + rs.getString("name"));
					System.out.println("Designation: " + rs.getString("designation"));
					System.out.println("Salary: " + rs.getInt("salary"));
					System.exit(0);
				}
				else
				{
					System.out.println("\nSorry, password is wrong. Please try again.\n");
					flag = false ;
				}
			}
		}
		if(flag)
			System.out.println("\nSorry, ID does not exist in the database. Please try again.\n");
		main(args); // running the program once more
	}
}
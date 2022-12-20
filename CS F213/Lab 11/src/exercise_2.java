import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class exercise_2
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS");
		Statement s = (Statement) con.createStatement();
		int[] ID = {100, 101, 102, 103};
		String[] fname = {"Zara", "Mahnaz", "Zaid", "Ravi"};
		String[] lname = {"Ali", "Fatma", "Khan", "Kant"};
		int[] age = {18, 25, 30, 35};
		for(int i = 0; i < 4; i++)
		{
			String data = "INSERT INTO registration \r\n" + 
					"VALUES (" + ID[i] + ", '" + fname[i] + "', '" + lname[i] + "', " + age[i] + ");" ;
			s.executeUpdate(data);
		}
	}
}
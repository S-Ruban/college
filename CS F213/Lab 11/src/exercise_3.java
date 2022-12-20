import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class exercise_3
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS");
		Statement s = (Statement) con.createStatement();
		System.out.println("ID	Firstname	Last Name	Age");
		System.out.println("-------------------------------------------");
		ResultSet rs = s.executeQuery("SELECT * FROM registration");
		while(rs.next())
		{
			System.out.println(rs.getInt("ID") + "\t " + rs.getString("Firstname") + "\t\t" + rs.getString("Last name") + "\t\t" + rs.getInt("Age"));
		}
	}
}
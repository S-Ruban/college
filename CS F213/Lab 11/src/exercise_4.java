import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class exercise_4
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS");
		Statement s = (Statement) con.createStatement();
		String update1 = "UPDATE registration\r\n" + 
				"SET Age = 30\r\n" + 
				"WHERE ID = 100" ;
		String update2 = "UPDATE registration\r\n" + 
				"SET Age = 30\r\n" + 
				"WHERE ID = 101" ;
		s.executeUpdate(update1);
		s.executeUpdate(update2);
	}
}
import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class exercise_5
{
	public static void main(String[] args) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS");
		Statement s = (Statement) con.createStatement();
		String delete = "DELETE FROM registration WHERE ID = 101" ;
		s.executeUpdate(delete);
	}
}
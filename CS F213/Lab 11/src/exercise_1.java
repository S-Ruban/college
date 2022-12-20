import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
public class exercise_1 {

	public static void main(String[] args) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/test?useSSL=false", "root", "JDBCOOPS");
		Statement s = (Statement) con.createStatement();
		String create = "CREATE TABLE `test`.`registration` (\r\n" + 
				"  `ID` INT NOT NULL,\r\n" + 
				"  `Firstname` VARCHAR(45) NOT NULL,\r\n" + 
				"  `Last name` VARCHAR(45) NULL,\r\n" + 
				"  `Age` VARCHAR(45) NOT NULL,\r\n" + 
				"  PRIMARY KEY (`ID`));\r\n" ;
		s.executeUpdate(create);
	}
}
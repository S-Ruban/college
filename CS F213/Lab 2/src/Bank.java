public class Bank
{
	String name, acno, address ;
	float balance ;
	char type ;
	void det1()
	{
		System.out.println("Account holder name : " + name);
		System.out.println("Account number : " + acno);
		System.out.println("Account balance : " + balance);
	}
	void det2()
	{
		det1();
		System.out.println("Address : " + address);
		System.out.println("Account type : " + type);
	}
	void deposit(float b, float amt)
	{
		balance += amt ;
	}
	void withdraw(float b, float amt)
	{
		withdraw(b, -amt);
	}
}
import java.util.Scanner ;
public class Shop 
{
	String ItemCode, ItemName ;
	double ItemCost ;
	int ItemCount ;
	Shop()
	{
		ItemCode = "1" ;
		ItemName = "APPLE" ;
		ItemCost = 10.0 ;
		ItemCount = 20 ;
	}
	void display()
	{
		System.out.println("ItemCode ItemName ItemCost ItemCount");
		System.out.println(ItemCode + "                 " +  ItemName + "        " + ItemCost + "          " + ItemCount);
	}
	void buy(int qty)
	{
		if(qty > ItemCount)
			System.out.println("SORRY ONLY " + ItemCount + " ITEMS AVAILABLE");
		else
		{
			System.out.println("COST OF THE ORDER IS " + qty*ItemCost);
			System.out.println("ORDER DETAILS");
			System.out.println("ItemCode ItemName ItemCount ItemCost");
			System.out.println(ItemCode + "                 " +  ItemName + "        " + qty + "          " + qty*ItemCost);
			ItemCount -= qty ;
			System.out.println("CURRENT AVAILABILITY");
			display();
		}
			
	}
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("DATA DISPLAY");
		Shop s = new Shop();
		s.display();
		System.out.println("Enter item code and quantity of the item : ");
		String ic = sc.next();
		int iq = sc.nextInt();
		s.buy(iq);
	}
}
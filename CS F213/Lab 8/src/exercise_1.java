import java.util.Scanner ;
import java.util.ArrayList ;
import java.util.Collections ;
public class exercise_1 
{
	 public static int lowerBound(ArrayList arr, int value)
	 {
		 if(arr.size() == 1)
			 return (int)arr.get(0);
        int low = 0;
        int high = arr.size();
        while (low < high) {
            final int mid = (low + high) / 2;
            //checks if the value is less than middle element of the array //PS : Stolen, #noc
            if (-value <= (int)arr.get(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return (int) arr.get(low);
	 }
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		ArrayList<Integer> pos = new ArrayList<Integer>();
		ArrayList<Integer> neg = new ArrayList<Integer>();
		int p1 = 0, p2 = 0, diff = -2147483647 ;
		int temp ;
		for(int i = 0; i < size; i++)
		{
			temp = sc.nextInt();
			if(temp >= 0)
				pos.add(temp);
			else
				neg.add(-temp);
		}
		Collections.sort(pos);
		Collections.sort(neg);
		if(neg.size() == 0)
			System.out.println((int)pos.get(0) + " " + (int)pos.get(1));
		else if(pos.size() == 0)
			System.out.println(-(int)neg.get(0) + " " + -(int)neg.get(1));
		else
		{
			diff = Math.abs((int)pos.get(0)-(int)neg.get(0));
			while((p1 < pos.size()) && (p2 < neg.size()))
			{
				if(Math.abs((int)neg.get(p2)-(int)pos.get(p1)) < Math.abs(diff))
					diff = Math.abs((int)pos.get(p1)-(int)neg.get(p2));
				if((int)neg.get(p2) > (int)pos.get(p1))
					p1++ ;
				else
					p2++ ;
			}
			if(p1 >= pos.size())
				p1 = pos.size()-1 ;
			if(p2 >= neg.size())
				p2 = neg.size()-1 ;
			System.out.println((int)pos.get(p1) + " " + -(int)neg.get(p2));
		}
	}
}
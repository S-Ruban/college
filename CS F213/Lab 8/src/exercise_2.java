import java.util.ArrayList ;
import java.util.Collections;
import java.util.Scanner ;
public class exercise_2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		for(int i = 0; i < size; i++)
			arr.add(sc.nextInt());
		Collections.sort(arr);
		int t = 0 ;
		for(int i = 0; i < size-2; i++)
		{
			for(int j = i+1; j < size-1; j++)
			{
				for(int k = j+1; k < size; k++)
				{
					if((int)arr.get(i)+(int)arr.get(j) > (int)arr.get(k))
						t++ ;
					else
						break ;
				}
			}
		}
		System.out.println(t);
	}
}
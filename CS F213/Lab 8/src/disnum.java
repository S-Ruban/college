import java.util.Scanner ;
import java.util.HashMap ;
public class disnum
{
	static int unique(int [] a, int b, int e)
	{
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>(); // using a HashMap to find out duplicates, each key will have value 1 (frequency) only
		for(int x = b; x < e; x++)
			map.put(a[x], map.getOrDefault(a[x], 0) + 1); // if key exists, it will increase its frequency, else add new key with frequency 1, all in O(1) complexity (constant time), O(n) worse case
		return map.size(); // total number of keys (guaranteed no duplicates)
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int arr[] = new int[N];
		for(int i = 0; i < N; i++)
			arr[i] = sc.nextInt();
		int B = sc.nextInt();
		for(int i = 0; i <= N-B; i++)
			System.out.print(unique(arr, i, i+B) + " ");
	}
}
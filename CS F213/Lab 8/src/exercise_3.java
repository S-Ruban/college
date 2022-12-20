import java.util.Arrays;
import java.util.Scanner ;
public class exercise_3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int s1 = sc.nextInt();
		int [] A = new int[s1];
		for(int i = 0; i < s1; i++)
			A[i] = sc.nextInt();
		int s2 = sc.nextInt();
		int [] B = new int[s1];
		for(int i = 0; i < s2; i++)
			B[i] = sc.nextInt();
		int [] C = new int[s1+s2];
		for(int i = 0; i < s1; i++)
			C[i] = A[i];
		for(int i = 0; i < s2; i++)
			C[i+s1] = B[i];
		Arrays.sort(C);
		for(int i = 0; i < s1; i++)
			System.out.print(C[i] + " ");
		System.out.println();
		for(int i = 0; i < s2; i++)
			System.out.println(C[i+s1] + " ");
	}
}
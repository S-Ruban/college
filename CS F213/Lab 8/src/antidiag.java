import java.util.Scanner ;
public class antidiag
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the size of the square matrix : ");
		int size = sc.nextInt();
		int arr[][] = new int[size][size];
		System.out.println("Enter the elements of the " + size + " x " + size + " array : ");
		for(int i = 0; i < size*size; i++)
			arr[i/size][i%size] = sc.nextInt(); // input the elements of the matrix, i/size is row index and i%size is column index
		int ad[][] = new int[2*size-1][]; // there will be 2s - 1 jagged arrays, where s is the size of the square matrix
		for(int i = 0; i < 2*size-1; i++)
			ad[i] = new int[size-Math.abs(i-size+1)]; // ith jagged array has size s-|i-s+1|
		for(int i = 0; i < 2*size-1; i++)
		{
			if(i > size-1) // lower half after dividing along the anti-diagonal
			{
				for(int j = 0; j < 2*size-i-1; j++)
					ad[i][j] = arr[i-size+1+j][size-1-j];
			}
			else
			{
				for(int j = 0; j <= size-Math.abs(i-size); j++) // upper half after dividing along the anti-diagonal
					ad[i][j] = arr[j][i-j];
			}
		}
		for(int i = 0; i < 2*size-1; i++) // print the jagged array
		{
			System.out.print("[");
			for(int j = 0; j < size-Math.abs(i-size+1)-1; j++)
				System.out.print(+ ad[i][j] + ", ");
			System.out.println(ad[i][size-Math.abs(i-size+1)-1] + "]");
		}
	}
}
public class exercise_5
{
	public static void main(String[] args)
	{
		for(int i = 100; i <= 500; i++)
		{
			if((i/100)*(i/100)*(i/100) + ((i-(i/100)*100)/10)*((i-(i/100)*100)/10)*((i-(i/100)*100)/10) + (i%10)*(i%10)*(i%10) == i)
				System.out.println(i + " is an Armstrong number.");
		}
	}
}
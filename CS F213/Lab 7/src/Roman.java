import java.util.Scanner ;
public class Roman
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int temp = a ;
		StringBuilder roman = new StringBuilder();
		for(int i = 0; i < temp/1000; i++)
			roman.append("M");
		int h = temp - (temp/1000)*1000 ;
		if((h/100)*100 == 900)
			roman.append("CM");
		else if((h/100)*100 == 400)
			roman.append("CD");
		else
		{
			if(h >= 500)
				roman.append("D");
			for(int i = 0; i < (h/100)%5; i++)
				roman.append("C");
		}
		int t = h - (h/100)*100 ;
		if((t/10)*10 == 90)
			roman.append("XC");
		else if((t/10)*10 == 40)
			roman.append("XL");
		else
		{
			if(t >= 50)
				roman.append("L");
			for(int i = 0; i < (t/10)%5; i++)
				roman.append("X");
		}
		if(temp % 10 == 9)
			roman.append("IX");
		else if(temp % 10 == 4)
			roman.append("IV");
		else
		{
			if(temp % 10 > 4)
				roman.append("V");
			for(int i = 0; i < (temp%10)%5; i++)
				roman.append("I");
		}
        // below method does the same, just uses less variables 
		/*
		 for(int i = 0; i < temp/1000; i++)
			roman.append("M");
		// int h = temp - (temp/1000)*1000 ;
		if(((temp - (temp/1000)*1000)/100)*100 == 900)
			roman.append("CM");
		else if(((temp - (temp/1000)*1000)/100)*100 == 400)
			roman.append("CD");
		else
		{
			if((temp - (temp/1000)*1000) >= 500)
				roman.append("D");
			for(int i = 0; i < ((temp - (temp/1000)*1000)/100)%5; i++)
				roman.append("C");
		}
		// int t = temp - (temp/1000)*1000 - ((temp - (temp/1000)*1000)/100)*100 ;
		if(((temp - (temp/1000)*1000 - ((temp - (temp/1000)*1000)/100)*100)/10)*10 == 90)
			roman.append("XC");
		else if(((temp - (temp/1000)*1000 - ((temp - (temp/1000)*1000)/100)*100)/10)*10 == 40)
			roman.append("XL");
		else
		{
			if((temp - (temp/1000)*1000 - ((temp - (temp/1000)*1000)/100)*100) >= 50)
				roman.append("L");
			for(int i = 0; i < ((temp - (temp/1000)*1000 - ((temp - (temp/1000)*1000)/100)*100)/10)%5; i++)
				roman.append("X");
		}
		if(temp % 10 == 9)
			roman.append("IX");
		else if(temp % 10 == 4)
			roman.append("IV");
		else
		{
			if(temp % 10 > 4)
				roman.append("V");
			for(int i = 0; i < (temp%10)%5; i++)
				roman.append("I");
		}  */
		System.out.println(roman.toString());
	}
}
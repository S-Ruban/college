import java.io.FileInputStream;	// importing library required to input data from a file
import java.io.IOException; 	// to automatically catch any exception during runtime
public class fileio
{
	public static void main(String[] args) throws IOException
	{
		FileInputStream fis = new FileInputStream("txt.txt");	// open file input stream to read data from the file
		int l, s = 0, w = 1, c = 0 ;	// to count number of sentences, words, characters and whitespaces
		while((l = fis.read()) != -1)	// reads each character from text file till it encounters EOF
		{
			c++ ;	// number of characters increased by 1
			if(l == 46)	// if '.' is encountered
				s++ ;
			if(l == 32) // if ' ' is encountered
				w++ ;
		}
		System.out.println("No of sentences: " + s);
		System.out.println("No of words: " + w);
		System.out.println("No of characters: " + (c-s-w+1));	// characters here is only alphabets, so removing count of fullstops and whitespaces
		System.out.println("No of whitespaces: " + (w-1));	// number of whitespaces is always one less than number of words
		fis.close();	// closing the stream to avoid any file I/O error
	}
}
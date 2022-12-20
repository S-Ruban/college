class ExHandling
{
	public static void main(String[] args)
	{
		String[] s = {"abc", "123", null, "xyz"};
		for (int i = 0; i < 6; i++)
		{
			try
			{
				int a = s[i].length() + Integer.parseInt(s[i]);
			}
			/*catch(NumberFormatException ex)
			{
				ex.printStackTrace();
			}
			catch (ArrayIndexOutOfBoundsException ex)
			{
				System.out.println(ex.toString());
			}
			catch (NullPointerException ex)
			{
				ex.printStackTrace();
			}
			finally
			{
				System.out.println("finally executed ");
			}*/
			catch(NumberFormatException | ArrayIndexOutOfBoundsException | NullPointerException ex)
			{
				System.out.println("hello");
			}
		}
	}
}
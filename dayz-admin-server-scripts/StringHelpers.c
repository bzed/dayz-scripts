static class StringHelpers
{
	static void Split(string text, string delim, out TStringArray list)
	{
		string temp = text + delim;
		string word = "";
		
		for (int i = 0; i < temp.Length(); i++ )
		{
			string x = temp.Get(i);
			
			if ( x != delim )
			{
				word = word + x;
			}
			else
			{
				list.Insert(word);
				word = "";
			}
		}
	}
	
	static string Trim(string text, string c)
	{
		if (text.Length() < 3)
		{
			return "";
		}
		
		int count = 0;
		
		int start = 0;
		int end = 0;

		for (int i = 0; i < text.Length(); i++)
		{
			if (text.Get(i) == c)
			{
				count++;
				start = i + 1;
				break;
			}
		}

		for (int j = text.Length() - 1; j >= 0; j--)
		{
			if (text.Get(j) == c)
			{
				count++;
				end = j - 1;
				break;
			}
		}
		
		// Return substring only if trimmed by c from both sides.
		if (count == 2)
		{
			return text.Substring(start, end - start + 1);
		}
		
		return "";
	}
}

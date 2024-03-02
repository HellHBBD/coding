import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Regex {
	private String string;

	public void setString(String string)
	{
		this.string = string.toLowerCase();
	}

	public void palindrome()
	{
		for (int head = 0, tail = string.length() - 1; head <= tail; head++, tail--) {
			if (string.charAt(head) != string.charAt(tail)) {
				System.out.print('N');
				return;
			}
		}
		System.out.print('Y');
	}

	public void contain(String str1)
	{
		int startIndex = 0;
		int index = 0;
		while (startIndex + index < string.length()) {
			if (index == str1.length()) {
				System.out.print('Y');
				return;
			}
			if (string.charAt(startIndex + index) == str1.charAt(index)) {
				index++;
			} else {
				startIndex++;
				index = 0;
			}
		}
		System.out.print('N');
	}

	public void containN(String str2, int n)
	{
		int startIndex = 0;
		int index = 0;
		while (startIndex + index < string.length()) {
			if (index == str2.length()) {
				n--;
				startIndex++;
				index = 0;
			}
			if (n == 0) {
				System.out.print('Y');
				return;
			}
			if (string.charAt(startIndex + index) == str2.charAt(index)) {
				index++;
			} else {
				startIndex++;
				index = 0;
			}
		}
		System.out.print('N');
	}

	public void containAB()
	{
		int a = 0, aMax = 0, b = 0, bMax = 0;
		for (int i = 0; i < string.length(); i++) {
			switch (string.charAt(i)) {
			case 'a':
				a++;
				b = 0;
				break;
			case 'b':
				b++;
				a = 0;
				break;
			default:
				a = b = 0;
			}
			if (a > aMax)
				aMax = a;
			if (b > bMax)
				bMax = b;
		}
		if (aMax * 2 <= bMax)
			System.out.print('Y');
		else
			System.out.print('N');
	}

	public void test(String string, String str1, String str2, int n)
	{
		setString(string);
		palindrome();
		System.out.print(',');
		contain(str1);
		System.out.print(',');
		containN(str2, n);
		System.out.print(',');
		containAB();
		System.out.println();
	}
}

class RegExp {
	public static void main(String[] args)
	{
		String str1 = args[1];
		String str2 = args[2];
		int n = Integer.parseInt(args[3]);
		Regex regex = new Regex();

		try {
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			String line;
			while ((line = reader.readLine()) != null) {
				//You main code should be invoked here
				regex.test(line, str1, str2, n);
			}
			reader.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

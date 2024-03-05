public class Regex {
	private String string;

	public void setString(String string)
	{
		this.string = string.toLowerCase();
	}

	public void palindrome()
	{
		for (int head = 0, tail = string.length() - 1; head < tail; head++, tail--) {
			if (string.charAt(head) != string.charAt(tail)) { //if once not match
				System.out.print('N');
				return;
			}
		}
		System.out.print('Y'); //all match
	}

	public void contain(String str1)
	{
		int startIndex = 0;
		int index = 0;
		while (true) {
			if (index == str1.length()) { //match whole str1
				System.out.print('Y');
				return;
			} else if (startIndex + index == string.length()) {
				//no match in whole string
				System.out.print('N');
				return;
			} else if (string.charAt(startIndex + index) == str1.charAt(index)) {
				//match one char -> test next char
				index++;
			} else { //not match -> test next substring
				startIndex++;
				index = 0;
			}
		}
	}

	public void containN(String str2, int n)
	{
		int startIndex = 0;
		int index = 0;
		while (true) {
			if (index == str2.length()) { //match -> minus to count
				n--;
				startIndex++;
				index = 0;
			} else if (n == 0) { //match require count
				System.out.print('Y');
				return;
			} else if (startIndex + index == string.length()) {
				//no match count in whole string
				System.out.print('N');
				return;
			} else if (string.charAt(startIndex + index) == str2.charAt(index)) {
				//match one char -> test next char
				index++;
			} else { //not match -> test next substring
				startIndex++;
				index = 0;
			}
		}
	}

	public void containAB()
	{
		//all case must contain "a" and "bb"
		int aIndex = -1, bIndex = -1;
		for (int i = 0; i < string.length(); i++) { //find "a" from the front
			if (string.charAt(i) == 'a') {
				aIndex = i;
				break;
			}
		}
		if (aIndex == -1) { //"a" must find once
			System.out.print('N');
			return;
		}
		for (int i = string.length() - 1; i > 0; i--) { //find "bb" from the end
			if (string.charAt(i) == 'b' && string.charAt(i - 1) == 'b') {
				bIndex = i;
				break;
			}
		}
		if (bIndex > aIndex) //if "bb" is at the right of "a"
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

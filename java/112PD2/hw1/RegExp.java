import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

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

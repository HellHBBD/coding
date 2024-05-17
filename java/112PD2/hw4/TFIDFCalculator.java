import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.ArrayList;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class TFIDFCalculator {
	public static ArrayList<Trie> read(String docs) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(docs));
		String line;
		if ((line = br.readLine()) != null) {
			System.out.println(line);
			Matcher match = Pattern.compile("[a-zA-Z]+").matcher(line);
			while (match.find()) {
				String word = match.group().toLowerCase();
				System.out.println(word);
			}
		}
		br.close();
		return null;
	}

	public static void main(String[] args) throws IOException {
		read(args[0]);
	}
}

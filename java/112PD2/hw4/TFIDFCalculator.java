import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.ArrayList;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class TFIDFCalculator {
	public static TFIDF read(String name) throws IOException {
		TFIDF docs = new TFIDF();
		BufferedReader br = new BufferedReader(new FileReader(name));
		String line;
		int lineCount = 1;
		// temp to store each text
		Text temp = new Text();
		while ((line = br.readLine()) != null) {
			// System.out.println(line);
			Matcher match = Pattern.compile("[a-zA-Z]+").matcher(line);
			// five lines -> one text
			if (lineCount % 5 == 0) {
				docs.addText(temp);
				temp = new Text();
			}
			while (match.find()) {
				String word = match.group().toLowerCase();
				// System.out.println(word);
				// first time insert
				if (temp.getWord(word) == 0) {
					docs.addWord(word);
				}
				temp.add(word);
			}
		}
		br.close();
		return docs;
	}

	public static void main(String[] args) throws IOException {
		// TFIDF docs = read(args[0]);
		// System.out.println(docs.getWord("same"));
		TFIDF test = new TFIDF();

	}
}

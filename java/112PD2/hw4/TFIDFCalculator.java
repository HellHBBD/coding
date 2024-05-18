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
		Trie temp = new Trie();
		while ((line = br.readLine()) != null) {
			// System.out.println(line);
			Matcher match = Pattern.compile("[a-zA-Z]+").matcher(line);
			if (lineCount % 5 == 0){
				temp = new Trie();
			}
			while (match.find()) {
				String word = match.group().toLowerCase();
				// System.out.println(word);
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
		TFIDF docs = read(args[0]);
	}
}

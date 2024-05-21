import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;

// Ser
// import java.io.FileNotFoundException;
// import java.io.FileInputStream;
// import java.io.FileOutputStream;
// import java.io.ObjectInputStream;
// import java.io.ObjectOutputStream;

import java.util.ArrayList;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class TFIDFCalculator {
	public static TFIDF read(String name) throws IOException, ClassNotFoundException {
		TFIDF docs;
		// Ser
		// String serialName = name.replaceAll("/", ".");
		// try {
		// 	ObjectInputStream ois = new ObjectInputStream(new FileInputStream(serialName));
		// 	docs = (TFIDF) ois.readObject();
		// 	ois.close();
		// 	return docs;
		// } catch (FileNotFoundException e) {
		// 	;
		// }
		docs = new TFIDF();
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(name), "UTF-8"));
		String line;
		int lineCount = 0;
		// temp to store each text
		Text temp = new Text();
		Pattern pattern = Pattern.compile("[a-zA-Z]+");
		while ((line = br.readLine()) != null) {
			Matcher match = pattern.matcher(line);
			
			while (match.find()) {
				String word = match.group().toLowerCase();
				// System.out.print(word + " ");
				// first time insert
				// if (word.equals("same")) {
				// 	System.out.println(line);
				// }
				if (temp.getWord(word) == 0) {
					docs.addWord(word);
				}
				temp.add(word);
			}
			// five lines -> one text
			lineCount++;
			if (lineCount != 0 && lineCount % 5 == 0) {
				docs.addText(temp);
				temp = new Text();
			}
		}
		br.close();
		// Ser
		// ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(serialName));
		// oos.writeObject(docs);
		// oos.close();
		return docs;
	}

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		TFIDF docs = read(args[0]);
		// System.out.println(String.format("%.5f ", docs.tfidf("same", 30)));

		BufferedReader br = new BufferedReader(new FileReader(args[1]));
		String[] words = br.readLine().split(" ");
		String[] textIndex = br.readLine().split(" ");
		br.close();
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
		for (int i = 0;i < words.length;i++) {
			bw.write(String.format("%.5f ", docs.tfidf(words[i], Integer.parseInt(textIndex[i]))));
		}
		bw.close();
	}
}

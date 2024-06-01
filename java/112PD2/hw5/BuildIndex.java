import java.io.Serializable;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;

// Ser
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import java.util.ArrayList;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Trie implements Serializable {
	Trie[] children;
	int count;

	public Trie() {
		children = new Trie[26];
		count = 0;
	}

	public void add(String word) {
		Trie node = this;
		for (char c : word.toCharArray()) {
            if (node.children[c - 'a'] == null) {
                node.children[c - 'a'] = new Trie();
            }
            node = node.children[c - 'a'];
        }
        node.count++;
	}

	public int getCount(String word) {
		Trie node = this;
        for (char c : word.toCharArray()) {
            node = node.children[c - 'a'];
            if (node == null) {
                return 0;
            }
        }
        return node.count;
	}
}

class Text implements Serializable {
	int wordCount;
	Trie words;

	public Text(){
		wordCount= 0;
		words = new Trie();
	}

	public void add(String word){
		wordCount++;
		words.add(word);
	}

	public int getWordCount(){
		return wordCount;
	}

	public int getWord(String word){
		return words.getCount(word);
	}
}

class TFIDF implements Serializable{
	Trie wordCount;
	ArrayList<Text> text;

	public TFIDF() {
		wordCount = new Trie();
		text = new ArrayList<Text>();
	}

	public void addWord(String word){
		wordCount.add(word);
	}

	public void addText(Text text){
		this.text.add(text);
	}

	public int getWord(String word){
		return wordCount.getCount(word);
	}

	public double tf(String word, int textIndex){
		Text temp = text.get(textIndex);
		// System.out.println(temp.getWord(word));
		// System.out.println(temp.getWordCount());
		return (double)temp.getWord(word) / temp.getWordCount();
	}

	public double idf(String word){
		// System.out.println(text.size());
		// System.out.println(getWord(word));
		return Math.log((double)text.size() / getWord(word));
	}

	public double tfidf(String word, int textIndex){
		return tf(word, textIndex) * idf(word);
	}
}

public class BuildIndex {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		String pathname = args[0];
		Matcher pathmatch = Pattern.compile("(?<name>\\w+)\\.txt").matcher(pathname);
		String filename = null;
		if (pathmatch.find()) {
			filename = pathmatch.group("name") + ".ser";
		}
		System.out.println(filename);
		TFIDF docs = new TFIDF();
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(pathname), "UTF-8"));
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
		FileOutputStream fos = new FileOutputStream(filename);
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		oos.writeObject(docs);
		oos.close();

		// BufferedReader br = new BufferedReader(new FileReader(args[1]));
		// String[] words = br.readLine().split(" ");
		// String[] textIndex = br.readLine().split(" ");
		// br.close();
		// BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
		// for (int i = 0;i < words.length;i++) {
		// 	bw.write(String.format("%.5f ", docs.tfidf(words[i], Integer.parseInt(textIndex[i]))));
		// }
		// bw.close();
	}
}

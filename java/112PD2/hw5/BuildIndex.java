// import java.io.Serializable;
import java.io.Externalizable;
import java.io.ObjectInput;
import java.io.ObjectOutput;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FileInputStream;

// Ser
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

import java.util.ArrayList;
import java.util.HashMap;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Trie implements Externalizable {
	HashMap<String, Integer> map;

	public Trie() {
		map = new HashMap<String, Integer>();
	}

	public void add(String word) {
		if (map.containsKey(word)) {
			map.replace(word, map.get(word) + 1);
		} else {
			map.put(word, 1);
		}
	}

	public int get(String word) {
		return map.getOrDefault(word, 0);
	}

	@Override
	public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
		int n = in.readInt();
		for (int i = 0;i < n;i++) {
			String key = in.readUTF();
			int value = in.readInt();
			map.put(key, value);
		}
	}

	@Override
	public void writeExternal(ObjectOutput out) throws IOException {
		int n = map.size();
		out.writeInt(n);
		for (HashMap.Entry<String, Integer> entry : map.entrySet()) {
			String key = entry.getKey();
			int value = entry.getValue();
			out.writeUTF(key);
			out.writeInt(value);
		}
		out.flush();
	}
}

class Text implements Externalizable {
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

	public int getTotal(){
		return wordCount;
	}

	public int getWord(String word){
		return words.get(word);
	}

	@Override
	public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
		wordCount = in.readInt();
		words = (Trie) in.readObject();
	}

	@Override
	public void writeExternal(ObjectOutput out) throws IOException {
		out.writeInt(wordCount);
		out.writeObject(words);
		out.flush();
	}
}

class TFIDF implements Externalizable {
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
		return wordCount.get(word);
	}

	public int size() {
		return text.size();
	}

	public double tf(String word, int textIndex){
		Text temp = text.get(textIndex);
		return (double)temp.getWord(word) / temp.getTotal();
	}

	public double idf(String word){
		int count = getWord(word);
		if (count == 0) {
			return 0;
		}
		return Math.log((double)text.size() / count);
	}

	public double tfidf(String word, int textIndex){
		return tf(word, textIndex) * idf(word);
	}

	@Override
	public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
		wordCount = (Trie) in.readObject();
		text = (ArrayList<Text>) in.readObject();
	}

	@Override
	public void writeExternal(ObjectOutput out) throws IOException {
		out.writeObject(wordCount);
		out.writeObject(text);
		out.flush();
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
	}
}

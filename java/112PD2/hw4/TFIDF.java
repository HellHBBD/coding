import java.io.Serializable;

import java.util.ArrayList;

public class TFIDF implements Serializable{
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
		System.out.println(temp.getWord(word));
		System.out.println(temp.getWordCount());
		return (double)temp.getWord(word) / temp.getWordCount();
	}

	public double idf(String word){
		System.out.println(text.size());
		System.out.println(getWord(word));
		return Math.log((double)text.size() / getWord(word));
	}

	public double tfidf(String word, int textIndex){
		return tf(word, textIndex) * idf(word);
	}
}

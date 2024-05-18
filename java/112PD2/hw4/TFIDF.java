import java.util.ArrayList;

public class TFIDF {
	Trie wordCount;
	ArrayList<Text> text;

	public TFIDF() {
		Trie wordCount = new Trie();
		text = new ArrayList<Text>();
	}

	public void addWord(String word){
		wordCount.add(word);
	}

	public void addText(Text text){
		text.add(text);
	}

	public int getWord(String word){
		return wordCount.getCount(word);
	}

	public double tf(String word, int textIndex){
		Text temp = text.get(textIndex - 1);
		return (double)temp.getWord(word) / temp.getWordCount();
	}

	public double idf(String word){
		return Math.log((double)text.size() / getWord(word));
	}

	public double tfidf(String word, int textIndex){
		return tf(word, textIndex) * idf(word);
	}
}

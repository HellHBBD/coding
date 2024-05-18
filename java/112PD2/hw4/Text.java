public class Text{
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

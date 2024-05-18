public class Trie {
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

	// public static void main(String[] args) {
	// 	Trie t = new Trie();
	// 	System.out.println(t.getCount("hello"));
	// 	t.add("hello");
	// 	System.out.println(t.getCount("hello"));
	// 	t.add("hello");
	// 	System.out.println(t.getCount("hello"));
	// 	System.out.println(t.getCount("he"));
	// }
}

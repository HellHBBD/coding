import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

// Ser
import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.ObjectInputStream;

import java.util.Arrays;
import java.util.Comparator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Unit {
	public double tfidf;
	public int textIndex;

	Unit() {
		tfidf = 0;
		textIndex = -1;
	}

	public void print(BufferedWriter bw) throws IOException {
		bw.write(textIndex + " ");
	}
}

class PriorityList {
	Unit[] list;

	PriorityList(int n) {
		list = new Unit[n];
		for (int i = 0;i < n;i++) {
			list[i] = new Unit();
		}
	}

	public void push(double tfidf, int textIndex) {
		if (tfidf > list[0].tfidf) {
			list[0].tfidf = tfidf;
			list[0].textIndex = textIndex;
		} else {
			return;
		}
		for (int i = 1;i < list.length;i++) {
			if (list[i-1].tfidf > list[i].tfidf) {
				Unit temp = list[i-1];
				list[i-1] = list[i];
				list[i] = temp;
			} else {
				return;
			}
		}
	}

	public void print(BufferedWriter bw) throws IOException {
		for (int i = list.length - 1;i >= 0;i--) {
			list[i].print(bw);
		}
		bw.write("\n");
	}

	public void OR(Indexer indexer, String[] words) {
		int indexerSize = indexer.size();
		int wordCount = words.length;

		for (int i = 0;i < indexerSize;i++) { // for each text
			double total = 0;
			boolean notZero = false;
			for (int j = 0;j < wordCount;j++) { // for each word
				double tfidf = indexer.tfidf(words[j], i);
				total += tfidf;
				if (tfidf != 0) { // record once not zero
					notZero = true;
				}
			}
			if (notZero) { // if OR condition true
				push(total, i);
			}
		}
	}

	public void AND(Indexer indexer, String[] words) {
		int indexerSize = indexer.size();
		int wordCount = words.length;

		for (int i = 0;i < indexerSize;i++) { // for each text
			double total = 0;
			boolean zero = false;
			for (int j = 0;j < wordCount;j++) { // for each word
				double tfidf = indexer.tfidf(words[j], i);
				if (tfidf == 0) { // record once zero
					zero = true;
					break;
				}
				total += tfidf;
			}
			if (!zero) { // if AND condition true
				push(total, i);
			}
		}
	}

	public void clear() {
		for (Unit i : list) {
			i.tfidf = 0;
			i.textIndex = -1;
		}
	}
}

public class TFIDFSearch {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Indexer indexer = null;
		ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream(args[0] + ".ser")));
		//trace
		System.out.print("reading data ...");

		indexer = (Indexer) ois.readObject();
		//trace
		if (indexer != null) {
			System.out.println(" success!!");
		} else {
			System.out.println(" fail!!");
		}

		ois.close();
		BufferedReader br = new BufferedReader(new FileReader(args[1]), 16384);
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"), 16384);
		int n = Integer.parseInt(br.readLine());
		PriorityList pl = new PriorityList(n);
		String line = null;
		while ((line = br.readLine()) != null) {
			Matcher match = Pattern.compile("OR").matcher(line);
			String[] words = line.split("[ ANDOR]+");
			if (match.find()) {
				pl.OR(indexer, words);
			} else {
				pl.AND(indexer, words);
			}
			pl.print(bw);
			pl.clear();
		}
		System.out.println("done");
		bw.close();
		br.close();
	}
}

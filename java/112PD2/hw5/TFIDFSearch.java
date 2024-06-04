import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;

// Ser
import java.io.ObjectInputStream;

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

	public void OR(TFIDF docs, String[] words) {
		int docsSize = docs.size();
		int wordCount = words.length;
		double[] idf = new double[wordCount];

		for (int j = 0;j < wordCount;j++) { // initialize idf table
			idf[j] = docs.idf(words[j]);
		}

		for (int i = 0;i < docsSize;i++) { // for each text
			double tf = 0, result = 0;
			boolean notZero = false;
			for (int j = 0;j < wordCount;j++) { // for each word
				tf = docs.tf(words[j], i);
				result += tf * idf[j];
				if (tf != 0) { // record once not zero
					notZero = true;
				}
			}
			if (notZero) { // if OR condition true
				push(result, i);
			}
		}
	}

	public void AND(TFIDF docs, String[] words) {
		int docsSize = docs.size();
		int wordCount = words.length;
		double[] idf = new double[wordCount];

		for (int j = 0;j < wordCount;j++) { // initialize idf table
			idf[j] = docs.idf(words[j]);
		}

		for (int i = 0;i < docsSize;i++) { // for each text
			double tf = 0, result = 0;
			boolean zero = false;
			for (int j = 0;j < wordCount;j++) { // for each word
				tf = docs.tf(words[j], i);
				result += tf * idf[j];
				if (tf == 0) { // record once zero
					zero = true;
					break;
				}
			}
			if (!zero) { // if AND condition true
				push(result, i);
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
	public static void main(String[] args) throws IOException, ClassNotFoundException  {
		TFIDF docs = null;
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream(args[0] + ".ser"));
		//trace
		System.out.print("reading data ...");

		docs = (TFIDF) ois.readObject();
		//trace
		if (docs != null) {
			System.out.println("\rreading data ... success!!");
		} else {
			System.out.println("\rreading data ... fail!!");
		}

		ois.close();
		BufferedReader br = new BufferedReader(new FileReader(args[1]));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
		int n = Integer.parseInt(br.readLine());
		PriorityList pl = new PriorityList(n);
		String line = null;
		//trace
		int lineNumber = 1;

		while ((line = br.readLine()) != null) {
			//trace
			System.out.print("\rsearching line " + lineNumber++);

			Matcher match = Pattern.compile("OR").matcher(line);
			String[] words = line.split("[ ANDOR]+");
			if (match.find()) {
				pl.OR(docs, words);
			} else {
				pl.AND(docs, words);
			}
			pl.print(bw);
			pl.clear();
		}
		System.out.println("\ndone");
		bw.close();
		br.close();
	}
}

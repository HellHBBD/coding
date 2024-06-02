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

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TFIDFSearch {
	public static void main(String[] args) throws IOException, ClassNotFoundException  {
		TFIDF docs = null;
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream(args[0] + ".ser"));
		docs = (TFIDF) ois.readObject();
		ois.close();
		BufferedReader br = new BufferedReader(new FileReader(args[1]));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
		int n = Integer.parseInt(br.readLine());
		String line = null;
		while ((line = br.readLine()) != null) {
			Matcher match = Pattern.compile("OR").matcher(line);
			boolean OR;
			if (match.find()) {
				OR = true;
			} else {
				OR = false;
			}
			String[] words = line.split("[ ANDOR]+");
		}
		bw.close();
		br.close();
	}
}

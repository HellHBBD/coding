import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;

public class CodeGenerator {
	public static void main(String[] args)
	{
		ArrayList<Class> classes = new ArrayList<Class>();
		Class temp = new Class("public", "Teacher");
		temp.addVariable("public", "String", "id");
		temp.addFunction("public", "void", "teach");
		classes.add(temp);
		for (Class c : classes) {
			c.print();
		}
		// try {
		// 	BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		// 	String line;
		// 	while ((line = reader.readLine()) != null) {
		// 		String[] words = line.replaceFirst("^\\s+", "").replaceAll("\\W", " $0 ").split("\\s+");
		// 		for (String word : words) {
		// 			System.out.println("\"" + word + "\"");
		// 		}
		// 		System.out.println(Arrays.toString(words));
		// 	}
		// 	reader.close();
		// } catch (IOException e) {
		// 	e.printStackTrace();
		// }
	}
}

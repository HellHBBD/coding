import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;

public class CodeGenerator {
	public static void main(String[] args)
	{
		HashMap<String, Class> classes = new HashMap<String, Class>();

		try {
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			String line;
			Class currentClass = null;
			int length;

			while ((line = reader.readLine()) != null) {
				String[] words = line.replaceAll("[:\\+\\-\\(\\)\\{\\},]", " $0 ")
							 .replaceFirst("^\\s+", "")
							 .split("\\s+");
				length = words.length;
				// System.out.println(Arrays.toString(words));
				if (length >= 2 && words[0].equals("class")) { //declare class
					currentClass = new Class(words[1]);
					classes.put(words[1], currentClass);
					// if (length == 3 && words[2].equals("{")) { //still in class scope
					if (length == 3) { //still in class scope
						currentClass = classes.get(words[1]);
					}
				} else if (length >= 2 &&
					   words[1].equals(":")) { //change class scope
					currentClass = classes.get(words[0]);
					String visibility = words[2].equals("+") ? "public" :
										   "private";
					if (length >= 5 && words[4].equals("(")) { //function
						String name = words[3];
						String type = words[length - 1];
						Function function =
							new Function(visibility, type, name);
						for (int i = 5;; i += 2) {
							if (words[i].equals(",")) {
								i++;
							} else if (words[i].equals(")")) {
								break;
							}
							function.add(words[i], words[i + 1]);
						}
						currentClass.attributes.add(function);
					} else { //variable
						currentClass.addVariable(visibility, words[3],
									 words[4]);
					}
				} else if (length >= 3) {
					String visibility = words[0].equals("+") ? "public" :
										   "private";
					if (words[2].equals("(")) { //function
						String name = words[1];
						String type = words[length - 1];
						Function function =
							new Function(visibility, type, name);
						for (int i = 3;; i += 2) {
							if (words[i].equals(",")) {
								i++;
							} else if (words[i].equals(")")) {
								break;
							}
							function.add(words[i], words[i + 1]);
						}
						currentClass.attributes.add(function);
					} else { //variable
						currentClass.addVariable(visibility, words[1],
									 words[2]);
					}
				}
			}
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		for (String c : classes.keySet()) {
			try {
				String output = "Example.java";
				String content = "this is going to be written into file";
				File file = new File(c + ".java");
				if (!file.exists()) {
					file.createNewFile();
				}
				try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
					classes.get(c).print(bw);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CodeGenerator {
	public static void main(String[] args)
	{
		HashMap<String, Class> classes = new HashMap<String, Class>();

		try {
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			String line;
			Class currentClass = null;
			Matcher match;

			while ((line = reader.readLine()) != null) {
				line = line.replaceAll("\\s+", " ")
						   .replaceAll("\\( ", "\\(")
						   .replaceAll(" ,", ",")
						   .replaceAll(" \\)", "\\)");
				match = Pattern.compile("\\s*class\\s+(?<class>\\w+)\\s*\\{").matcher(line); //class with bracket
				if (match.find()) {
					String Class = match.group("class");
					if (!classes.containsKey(Class)) {
						currentClass = new Class(Class);
						classes.put(Class, currentClass);
					} else {
						currentClass = classes.get(Class);
					}
					continue;
				}

				match = Pattern.compile("\\s*class\\s+(?<class>\\w+)").matcher(line);
				if (match.find()) {
					String Class = match.group("class");
					if (!classes.containsKey(Class)) {
						currentClass = new Class(Class);
						classes.put(Class, currentClass);
					}
					continue;
				}

				match = Pattern.compile("\\s*(?<class>\\w+)\\s*:\\s*(?<visibility>[+-])\\s*(?<name>\\w+)(?<arguments>\\(.*\\))\\s+(?<type>[\\w\\[\\]]+)").matcher(line);
				if (match.find()) {
					String Class = match.group("class");
					String visibility = match.group("visibility").equals("+") ?
								    "public" :
								    "private";
					String name = match.group("name");
					String arguments = match.group("arguments");
					String type = match.group("type");
					currentClass = classes.get(Class);
					currentClass.addFunction(visibility, type, name, arguments);
					continue;
				}

				match = Pattern.compile("\\s*(?<class>\\w+)\\s*:\\s*(?<visibility>[+-])\\s*(?<type>.*)\\s+(?<name>\\w+)").matcher(line);
				if (match.find()) {
					String Class = match.group("class");
					String visibility = match.group("visibility").equals("+") ?
								    "public" :
								    "private";
					String name = match.group("name");
					String type = match.group("type");
					currentClass = classes.get(Class);
					currentClass.addVariable(visibility, type, name);
					continue;
				}

				match = Pattern.compile("\\s*(?<visibility>[+-])\\s*(?<name>\\w+)(?<arguments>\\(.*\\))\\s+(?<type>[\\w\\[\\]]+)").matcher(line);
				if (match.find()) {
					String visibility = match.group("visibility").equals("+") ?
								    "public" :
								    "private";
					String name = match.group("name");
					String arguments = match.group("arguments");
					String type = match.group("type");
					currentClass.addFunction(visibility, type, name, arguments);
					continue;
				}

				match = Pattern.compile("\\s*(?<visibility>[+-])\\s*(?<type>.*)\\s+(?<name>\\w+)").matcher(line);
				if (match.find()) {
					String visibility = match.group("visibility").equals("+") ?
								    "public" :
								    "private";
					String name = match.group("name");
					String type = match.group("type");
					currentClass.addVariable(visibility, type, name);
					continue;
				}
			}
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		for (String c : classes.keySet()) {
			try {
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

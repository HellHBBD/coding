import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.IOException;

class Attribute {
	String visibility;
	String type;
	String name;
	public Attribute()
	{
		visibility = null;
		type = null;
		name = null;
	}
	public void print(BufferedWriter bw) throws IOException
	{
	}
}

class Variable extends Attribute {
	public Variable(String type, String name)
	{
		this.type = type;
		this.name = name;
	}
	public Variable(String visibility, String type, String name)
	{
		this.visibility = visibility;
		this.type = type;
		this.name = name;
	}
	@Override public void print(BufferedWriter bw) throws IOException
	{
		// System.out.println(visibility + " " + type + " " + name + ";");
		bw.write(visibility + " " + type + " " + name + ";\n");
	}
}

class Function extends Attribute {
	String arguments;
	public Function(String visibility, String type, String name, String arguments)
	{
		this.visibility = visibility;
		this.type = type;
		this.name = name;
		// arguments = new ArrayList<Variable>();
		this.arguments = arguments;
	}
	// public void add(String type, String name)
	// {
	// 	Variable variable = new Variable(type, name);
	// 	arguments.add(variable);
	// }
	@Override public void print(BufferedWriter bw) throws IOException
	{
		bw.write(visibility + " " + type + " " + name + arguments);
		// if (arguments.size() != 0) {
		// 	bw.write(arguments.get(0).type + " " + arguments.get(0).name);
		// 	for (int i = 1; i < arguments.size(); i++) {
		// 		bw.write(", ");
		// 		bw.write(arguments.get(i).type + " " + arguments.get(i).name);
		// 	}
		// }
		bw.write(" {");
		// bw.write(") {");
		if (name.contains("set")) {
			String temp = name.split("set")[1];
			String result = Character.toString(temp.charAt(0)).toLowerCase() + temp.substring(1);
			bw.write("\n        this." + result + " = " + result + ";\n    }\n");
		} else if (name.contains("get")) {
			String temp = name.split("get")[1];
			String result = Character.toString(temp.charAt(0)).toLowerCase() + temp.substring(1);
			bw.write("\n        return " + result + ";\n    }\n");
		} else if (type.equals("void")) {
			bw.write(";}\n");
		} else if (type.equals("int")) {
			bw.write("return 0;}\n");
		} else if (type.equals("String")) {
			bw.write("return \"\";}\n");
		} else if (type.equals("boolean")) {
			bw.write("return false;}\n");
		}
	}
}

public class Class {
	ArrayList<Attribute> attributes;
	String name;
	public Class(String name)
	{
		this.name = name;
		attributes = new ArrayList<Attribute>();
	}
	public void addVariable(String visibility, String type, String name)
	{
		Variable variable = new Variable(visibility, type, name);
		attributes.add(variable);
	}
	public void addFunction(String visibility, String type, String name, String arguments)
	{
		Function function = new Function(visibility, type, name, arguments);
		attributes.add(function);
	}
	public void print(BufferedWriter bw) throws IOException
	{
		bw.write("public class " + name + " {\n");
		for (Attribute attribute : attributes) {
			bw.write("    ");
			attribute.print(bw);
		}
		bw.write("}");
	}
}

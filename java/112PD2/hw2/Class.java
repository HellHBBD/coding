import java.util.ArrayList;

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
	public void print()
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
	@Override public void print()
	{
		System.out.println(visibility + " " + type + " " + name + ";");
	}
}

class Function extends Attribute {
	ArrayList<Variable> arguments;
	public Function(String visibility, String type, String name)
	{
		this.visibility = visibility;
		this.type = type;
		this.name = name;
		arguments = new ArrayList<Variable>();
	}
	public void add(String type, String name)
	{
		Variable variable = new Variable(type, name);
		arguments.add(variable);
	}
	@Override public void print()
	{
		System.out.print(visibility + " " + type + " " + name + "(");
		if (arguments.size() != 0) {
			System.out.print(arguments.get(0).type + " " + arguments.get(0).name);
			for (int i = 1; i < arguments.size(); i++) {
				System.out.print(", ");
				System.out.print(arguments.get(i).type + " " +
						 arguments.get(i).name);
			}
		}
		System.out.println(") {;}");
	}
}

public class Class {
	ArrayList<Attribute> attributes;
	String visibility;
	String name;
	public Class(String visibility, String name)
	{
		this.visibility = visibility;
		this.name = name;
		attributes = new ArrayList<Attribute>();
	}
	public void addVariable(String visibility, String type, String name)
	{
		Variable variable = new Variable(visibility, type, name);
		attributes.add(variable);
	}
	public void addFunction(String visibility, String type, String name)
	{
		Function function = new Function(visibility, type, name);
		attributes.add(function);
	}
	public void print()
	{
		System.out.println(visibility + " class " + name + " {");
		for (Attribute attribute : attributes) {
			System.out.print("    ");
			attribute.print();
		}
		System.out.print("}");
	}
}

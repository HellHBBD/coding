import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

interface a {
	public void say();
}

abstract class b {
	public void say() {
		System.out.println("hello");
	}
}

public class staticMethod extends b implements a {
	public static void main(String[] args) {
		staticMethod t = new staticMethod();
		t.say();
		System.out.println(t.getClass().getSuperclass().getName());
	}
}

import org.jsoup.Jsoup;
import org.jsoup.nodes.*;
import org.jsoup.select.*;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.*;

import java.util.ArrayList;

public class HtmlParser {
	public static void crawl() throws IOException
	{
		Document document = Jsoup.connect("https://pd2-hw3.netdb.csie.ncku.edu.tw/").get();
		File file = new File("data.csv");
		BufferedWriter bw;
		if (file.exists()) {
			bw = new BufferedWriter(new FileWriter(file, true));
		} else {
			file.createNewFile();
			bw = new BufferedWriter(new FileWriter(file, true));
			Elements stocks = document.select("th");
			for (Element element : stocks) {
				if (element.elementSiblingIndex() == 0) {
					bw.write(element.text());
					// System.out.print(element.text());
				} else {
					bw.write("," + element.text());
					// System.out.print("," + element.text());
				}
			}
			bw.write("\n");
			// System.out.print('\n');
		}

		Elements prices = document.select("td");
		for (Element element : prices) {
			if (element.elementSiblingIndex() == 0) {
				bw.write(element.text());
				// System.out.print(element.text());
			} else {
				bw.write("," + element.text());
				// System.out.print("," + element.text());
			}
		}
		bw.write("\n");
		bw.close();
	}

	public static void copy() throws IOException
	{
		File data = new File("data.csv");
		File output = new File("output.csv");
		Files.copy(data.toPath(), output.toPath());
	}

	public static ArrayList<Double> read(String stock, int start, int end) throws IOException
	{
		ArrayList<Double> data = new ArrayList<Double>();
		BufferedReader reader = new BufferedReader(new FileReader("data.csv"));
		String[] stocks = reader.readLine().split(",");

		int index = -1;
		for (int i = 0; i < stocks.length; i++) {
			if (stocks[i].equals(stock)) {
				index = i;
				break;
			}
		}

		String line;
		int count = 0;
		while ((line = reader.readLine()) != null && count < end) {
			count++;
			if (count >= start) {
				data.add(Double.valueOf(line.split(",")[index]));
			}
		}
		reader.close();
		return data;
	}

	public static void printDouble(BufferedWriter bw, double number) throws IOException
	{
		String temp = String.format("%.2f", number);
		for (int i = 0; i < temp.length(); i++) {
			if (temp.charAt(i) == '.') {
				if (temp.charAt(i + 2) != '0') {
					bw.write(String.format(".%c%c", temp.charAt(i + 1),
							       temp.charAt(i + 2)));
				} else if (temp.charAt(i + 1) != '0') {
					bw.write(String.format(".%c", temp.charAt(i + 1)));
				}
				return;
			} else {
				bw.write(temp.charAt(i));
			}
		}
	}

	public static void average(String stock, int start, int end) throws IOException
	{
		ArrayList<Double> data = read(stock, start, end);
		ArrayList<Double> result = new ArrayList<Double>();
		double total;
		for (int i = 0; i < data.size() - 4; i++) {
			total = 0;
			for (int j = 0; j < 5; j++) {
				total += data.get(i + j);
			}
			result.add(total / 5);
		}
		File file = new File("output.csv");
		BufferedWriter bw;
		if (file.exists()) {
			bw = new BufferedWriter(new FileWriter(file, true));
		} else {
			file.createNewFile();
			bw = new BufferedWriter(new FileWriter(file, true));
		}
		bw.write(String.format("%s,%d,%d\n", stock, start, end));
		printDouble(bw, result.get(0));
		for (int i = 1; i < result.size(); i++) {
			bw.write(",");
			printDouble(bw, result.get(i));
		}
		bw.write("\n");
		bw.close();
	}

	public static double squareRoot(double number)
	{
		double guess = number;
		while (true) {
			guess = (guess + number / guess) / 2.0;
			double test = guess * guess;
			if (test - number > 0 && test - number < 0.0001) {
				return guess;
			}
			if (number - test > 0 && number - test < 0.0001) {
				return guess;
			}
		}
	}

	public static void SD(String stock, int start, int end) throws IOException
	{
		ArrayList<Double> data = read(stock, start, end);
		double squareTotal = 0;
		double total = 0;
		int n = data.size();
		for (double element : data) {
			squareTotal += (element * element);
			total += element;
		}
		total /= n;
		double sd = squareRoot(squareTotal / (n - 1) - total * total * n / (n - 1));
		File file = new File("output.csv");
		BufferedWriter bw;
		if (file.exists()) {
			bw = new BufferedWriter(new FileWriter(file, true));
		} else {
			file.createNewFile();
			bw = new BufferedWriter(new FileWriter(file, true));
		}
		bw.write(String.format("%s,%d,%d\n", stock, start, end));
		printDouble(bw, sd);
		bw.write("\n");
		bw.close();
	}

	public static void top(int start, int end) throws IOException
	{
		ArrayList<Object[]> list = new ArrayList<Object[]>();
		BufferedReader reader = new BufferedReader(new FileReader("data.csv"));
		String[] stocks = reader.readLine().split(",");

		for (String stock : stocks) {
			Object[] temp = new Object[3];
			temp[0] = new String(stock);
			temp[1] = 0.0;
			temp[2] = 0.0;
			list.add(temp);
		}

		String line;
		int count = 0;
		int n = end - start + 1;
		while ((line = reader.readLine()) != null && count < end) {
			count++;
			if (count >= start) {
				stocks = line.split(",");
				for (int i = 0; i < stocks.length; i++) {
					double element = Double.valueOf(stocks[i]);
					Object[] temp = new Object[3];
					temp[0] = list.get(i)[0];
					temp[1] = (double)list.get(i)[1] + element * element;
					temp[2] = (double)list.get(i)[2] + element;
					list.set(i, temp);
				}
			}
		}
		reader.close();
		Object[][] top3 = new Object[3][2];
		top3[0][1] = 0.0;
		top3[1][1] = 0.0;
		top3[2][1] = 0.0;
		for (Object[] element : list) {
			double squareTotal = (double)element[1];
			double total = (double)element[2];
			double sd = squareRoot(squareTotal / (n - 1) - total * total / n / (n - 1));
			if (sd > (double)top3[0][1]) {
				top3[2][0] = top3[1][0]; //move 2nd to 3rd
				top3[2][1] = top3[1][1];
				top3[1][0] = top3[0][0]; //move 1st to 2nd
				top3[1][1] = top3[0][1];
				top3[0][0] = (String)element[0]; //assign new 1st
				top3[0][1] = sd;
			} else if (sd > (double)top3[1][1]) {
				top3[2][0] = top3[1][0]; //move 2nd to 3rd
				top3[2][1] = top3[1][1];
				top3[1][0] = (String)element[0]; //assign new 2nd
				top3[1][1] = sd;
			} else if (sd > (double)top3[2][1]) {
				top3[2][0] = (String)element[0]; //assign new 3rd
				top3[2][1] = sd;
			}
		}
		File file = new File("output.csv");
		BufferedWriter bw;
		if (file.exists()) {
			bw = new BufferedWriter(new FileWriter(file, true));
		} else {
			file.createNewFile();
			bw = new BufferedWriter(new FileWriter(file, true));
		}
		bw.write(String.format("%s,%s,%s,%d,%d\n", (String)top3[0][0], (String)top3[1][0], (String)top3[2][0], start, end));
		printDouble(bw, (double)top3[0][1]);
		bw.write(",");
		printDouble(bw, (double)top3[1][1]);
		bw.write(",");
		printDouble(bw, (double)top3[2][1]);
		bw.write("\n");
		bw.close();
	}

	public static void LR(String stock, int start, int end) throws IOException
	{
		ArrayList<Double> data = read(stock, start, end);
		int n = data.size();

		double Sx = 0;
		double Sy = 0;
		double Sxx = 0;
		double Sxy = 0;
		int day = start;
		for (double element : data) {
			Sy += element;
			Sx += day;
			Sxx += (day * day);
			Sxy += (element * day);
			day++;
		}
		double b1 = (Sxy - Sx * Sy / n) / (Sxx - Sx * Sx / n);
		double b0 = Sy / n - b1 * Sx / n;

		// double time = (start + end) * n / 2;
		// double price = 0;
		// for (double element : data) {
		// 	price += element;
		// }
		
		File file = new File("output.csv");
		BufferedWriter bw;
		if (file.exists()) {
			bw = new BufferedWriter(new FileWriter(file, true));
		} else {
			file.createNewFile();
			bw = new BufferedWriter(new FileWriter(file, true));
		}
		bw.write(String.format("%s,%d,%d\n", stock, start, end));
		printDouble(bw, b1);
		bw.write(",");
		printDouble(bw, b0);
		bw.write("\n");
		bw.close();
	}

	public static void main(String[] args) throws IOException
	{
		int mode = Integer.parseInt(args[0]);
		int task, start, end;
		switch (mode) {
		case 0:
			crawl();
			break;
		case 1:
			task = Integer.parseInt(args[1]);
			switch (task) {
			case 0:
				copy();
				break;
			case 1:
				start = Integer.parseInt(args[3]);
				end = Integer.parseInt(args[4]);
				average(args[2], start, end);
				break;
			case 2:
				start = Integer.parseInt(args[3]);
				end = Integer.parseInt(args[4]);
				SD(args[2], start, end);
				break;
			case 3:
				start = Integer.parseInt(args[3]);
				end = Integer.parseInt(args[4]);
				top(start, end);
				break;
			case 4:
				start = Integer.parseInt(args[3]);
				end = Integer.parseInt(args[4]);
				LR(args[2], start, end);
			}
		}
	}
}

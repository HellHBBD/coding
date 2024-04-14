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
import java.util.Arrays;

public class HtmlParser {
	public static void crawl()
	{
		try {
			Document document =
				Jsoup.connect("https://pd2-hw3.netdb.csie.ncku.edu.tw/").get();
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
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void copy()
	{
		try {
			File data = new File("data.csv");
			File output = new File("output.csv");
			Files.copy(data.toPath(), output.toPath());
		} catch (IOException e) {
		}
	}

	public static ArrayList<Double> read(String stock, int start, int end)
	{
		ArrayList<Double> data = new ArrayList<Double>();
		try {
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
			while ((line = reader.readLine()) != null) {
				count++;
				if (count >= start && count <= end) {
					data.add(Double.valueOf(line.split(",")[index]));
				}
			}
			reader.close();
		} catch (IOException e) {
		}
		return data;
	}

	public static void printDouble(BufferedWriter bw, double number) throws IOException
	{
		String temp = String.format("%.2f", number);
		for (int i = 0;i < temp.length();i++){
			if (temp.charAt(i) == '.'){
				if (temp.charAt(i+2) != '0'){
					bw.write(String.format(".%c%c",temp.charAt(i+1),temp.charAt(i+2)));
				}
				else if (temp.charAt(i+1) != '0'){
					bw.write(String.format(".%c",temp.charAt(i+1)));
				}
				return;
			}
			else{
				bw.write(temp.charAt(i));
			}
		}
	}

	public static void average(String stock, int start, int end)
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
		try {
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
			// System.out.print(String.format("%s,%d,%d\n%.2f", stock, start, end, result.get(0)));
			for (int i = 1; i < result.size(); i++) {
				bw.write(",");
				printDouble(bw, result.get(i));
				// System.out.print(String.format(",%.2f", result.get(i)));
			}
			bw.write("\n");
			// System.out.print("\n");
			bw.close();
		} catch (IOException e) {
		}
	}

	public static void SD(String stock, int start, int end)
	{
		ArrayList<Double> data = new ArrayList<Double>();
	}

	public static void top(int start, int end)
	{
	}

	public static void LR(String stock, int start, int end)
	{
		ArrayList<Double> data = new ArrayList<Double>();
	}

	public static void main(String[] args)
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

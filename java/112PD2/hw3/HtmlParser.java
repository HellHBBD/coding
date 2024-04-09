import org.jsoup.Jsoup;
import org.jsoup.nodes.*;
import org.jsoup.select.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class HtmlParser {
	public static void main(String[] args)
	{
		try {
			Document document = Jsoup.connect("https://pd2-hw3.netdb.csie.ncku.edu.tw/").get();
			File file = new File("data.csv");
			BufferedWriter bw;
			if (!file.exists()) {
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
			else {
				bw = new BufferedWriter(new FileWriter(file, true));
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
}

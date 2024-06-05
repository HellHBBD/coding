import java.io.Externalizable;
import java.io.ObjectInput;
import java.io.ObjectOutput;

import java.io.IOException;

import java.util.HashMap;

class Map implements Externalizable {
	HashMap<String, Double> map;

	public Map() {
		map = new HashMap<String, Double>();
	}

	public void put(String key, double value) {
		map.put(key, value);
	}

	public double getOrDefault(String key, double defaultValue) {
		return map.getOrDefault(key, defaultValue);
	}

	public int size() {
		return map.size();
	}

    @Override
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
		int n = in.readInt();
		for (int j = 0; j < n; j++) {
			String key = in.readUTF();
			double value = in.readDouble();
			put(key, value);
		}
    }

    @Override
    public void writeExternal(ObjectOutput out) throws IOException {
		int n = map.size();
		out.writeInt(n);
		for (HashMap.Entry<String, Double> entry : map.entrySet()) {
			String key = entry.getKey();
			double value = entry.getValue();
			out.writeUTF(key);
			out.writeDouble(value);
		}
        out.flush();
    }
}

public class Indexer implements Externalizable {
	Map[] list;

	public Indexer() {
	}

    public Indexer(TFIDF docs) {
        int n = docs.size();
        list = new Map[n];
        for (int i = 0; i < n; i++) {
			list[i] = new Map();
        }

        for (String word : docs.wordCount.map.keySet()) {
            double idf = docs.idf(word);
            for (int i = 0; i < n; i++) {
                double tf = docs.tf(word, i);
                if (tf != 0) {
                    list[i].put(word, tf * idf);
                }
            }
        }
    }

	public double tfidf(String word, int index) {
		return list[index].getOrDefault(word, 0.0);
	}

	public int size() {
		return list.length;
	}

    @Override
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        int m = in.readInt();
        list = new Map[m];
        for (int i = 0; i < m; i++) {
			list[i] = new Map();
            int n = in.readInt();
            for (int j = 0; j < n; j++) {
                String key = in.readUTF();
                double value = in.readDouble();
                list[i].put(key, value);
            }
        }
    }

    @Override
    public void writeExternal(ObjectOutput out) throws IOException {
        int m = list.length;
        out.writeInt(m);
        for (Map map : list) {
            int n = map.size();
            out.writeInt(n);
            for (HashMap.Entry<String, Double> entry : map.map.entrySet()) {
                String key = entry.getKey();
                double value = entry.getValue();
                out.writeUTF(key);
                out.writeDouble(value);
            }
        }
        out.flush();
    }
}

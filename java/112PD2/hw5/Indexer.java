import java.io.Externalizable;
import java.io.ObjectInput;
import java.io.ObjectOutput;

import java.io.IOException;

import java.util.ArrayList;
import java.util.HashMap;

public class Indexer implements Externalizable {
    ArrayList<HashMap<String, Double>> list;

	public Indexer() {
	}

    public Indexer(TFIDF docs) {
        int n = docs.size();
        list = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            list.add(new HashMap<>());
        }

        for (String word : docs.wordCount.map.keySet()) {
            double idf = docs.idf(word);
            for (int i = 0; i < n; i++) {
                double tf = docs.tf(word, i);
                if (tf != 0) {
                    list.get(i).put(word, tf * idf);
                }
            }
        }
    }

	public double tfidf(String word, int index) {
		return list.get(index).getOrDefault(word, 0.0);
	}

	public int size() {
		return list.size();
	}

    @Override
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        int m = in.readInt();
        list = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            HashMap<String, Double> temp = new HashMap<>();
            int n = in.readInt();
            for (int j = 0; j < n; j++) {
                String key = in.readUTF();
                double value = in.readDouble();
                temp.put(key, value);
            }
            list.add(temp);
        }
    }

    @Override
    public void writeExternal(ObjectOutput out) throws IOException {
        int m = list.size();
        out.writeInt(m);
        for (HashMap<String, Double> map : list) {
            int n = map.size();
            out.writeInt(n);
            for (HashMap.Entry<String, Double> entry : map.entrySet()) {
                String key = entry.getKey();
                double value = entry.getValue();
                out.writeUTF(key);
                out.writeDouble(value);
            }
        }
        out.flush();
    }
}

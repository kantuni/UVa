import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;

class Main {
  static class FastReader {
    BufferedReader reader;
    StringTokenizer tokenizer;
    
    FastReader() {
      reader = new BufferedReader(new InputStreamReader(System.in));
      tokenizer = new StringTokenizer("");
    }
    
    boolean hasNext() throws IOException {
      String line = reader.readLine();
      if (line != null) {
        tokenizer = new StringTokenizer(line);
        return true;
      }
      return false;
    }
    
    String next() throws IOException {
      while (!tokenizer.hasMoreElements()) {
        tokenizer = new StringTokenizer(reader.readLine());
      }
      return tokenizer.nextToken();
    }
    
    int nextInt() throws IOException {
      return Integer.parseInt(next());
    }
    
    double nextDouble() throws IOException {
      return Double.parseDouble(next());
    }
  }
  
  public static void main(String[] args) {
    FastReader reader = new FastReader();
    try {
      while (true) {
        int months = reader.nextInt();
        double downPayment = reader.nextDouble();
        double amount = reader.nextDouble();
        int nod = reader.nextInt();
        
        if (months < 0) {
          break;
        }
        
        ArrayList<Double> d = new ArrayList<>();
        for (int i = 0; i < nod; ++i) {
          int m = reader.nextInt();
          double p = reader.nextDouble();
          while (d.size() != m) {
            d.add(-1.0);
          }
          d.add(p);
        }
        
        double prev = d.get(0);
        for (int i = 1; i < d.size(); ++i) {
          if (d.get(i) == -1.0) {
            d.set(i, prev);
          } else {
            prev = d.get(i);
          }
        }
        
        ArrayList<Double> owe = new ArrayList<>();
        owe.add(amount);
        ArrayList<Double> cost = new ArrayList<>();
        double total = amount + downPayment;
        cost.add(total * (1.0 - d.get(0)));
        
        int count = 1;
        while (owe.get(owe.size() - 1) >= cost.get(cost.size() - 1)) {
          double lo = owe.get(owe.size() - 1);
          double lc = cost.get(cost.size() - 1);
          lo -= downPayment;
          owe.add(lo);
          if (count < d.size()) {
            lc *= 1.0 - d.get(count);
          } else {
            lc *= 1.0 - d.get(d.size() - 1);
          }
          cost.add(lc);
          ++count;
          System.out.println("Owe: " + owe);
          System.out.println("Cost: " + cost);
        }
        
        System.out.println(count - 1);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}

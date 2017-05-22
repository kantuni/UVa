import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Comparator;
import java.util.Arrays;

class Proposal {
  int index;
  String name;
  double price;
  double compliance;
  
  Proposal(int index, String name, double price, double compliance) {
    this.index = index;
    this.name = name;
    this.price = price;
    this.compliance = compliance;
  }
  
  public String toString() {
    return index + " " + name + " " + price + " " + compliance + "\n";
  }
}

class ProposalComparator implements Comparator<Proposal> {
  public int compare(Proposal p1, Proposal p2) {
    if (p1.compliance == p2.compliance) {
      if (p1.price == p2.price) {
        return (p1.index > p2.index) ? 1 : -1;
      } else {
        return (p1.price > p2.price) ? 1 : -1;
      }
    } else {
      return (p1.compliance < p2.compliance) ? 1 : -1;
    }
  }
}

class Main {
  static class FastReader {
    BufferedReader reader;
    StringTokenizer tokenizer;
    
    FastReader() {
      reader = new BufferedReader(new InputStreamReader(System.in));
      tokenizer = new StringTokenizer("");
    }
    
    String next() throws IOException {
      while (!tokenizer.hasMoreElements()) {
        tokenizer = new StringTokenizer(reader.readLine());
      }
      return tokenizer.nextToken();
    }
    
    String nextLine() throws IOException {
      return reader.readLine(); 
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
      int counter = 1;
      while (true) {
        int n = reader.nextInt();
        int p = reader.nextInt();
        
        if (n == 0 && p == 0) {
          break;
        }
        
        for (int i = 0; i < n; ++i) {
          String temp = reader.nextLine();
        }
        
        Proposal[] proposals = new Proposal[p];
        for (int i = 0; i < p; ++i) {
          String name = reader.nextLine();
          double d = reader.nextDouble();
          int r = reader.nextInt();
          proposals[i] = new Proposal(i, name, d, (double) r / n);
          for (int j = 0; j < r; ++j) {
            String temp = reader.nextLine();
          }
        }
        
        // sort proposals
        Arrays.sort(proposals, new ProposalComparator());
        
        if (counter > 1) {
          System.out.println();
        }
        System.out.println("RFP #" + counter);
        System.out.println(proposals[0].name);
        
        ++counter;
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

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
  }
  
  public static void main(String[] args) {
    FastReader reader = new FastReader();
    try {
      while (true) {
        int K = reader.nextInt();
        if (K == 0) {
          break;
        }
        int N = reader.nextInt();
        int M = reader.nextInt();
        for (int k = 0; k < K; k++) {
          int X = reader.nextInt();
          int Y = reader.nextInt();
          if (X == N || Y == M) {
            System.out.println("divisa");
          } else if (Y > M) {
            if (X > N) {
              System.out.println("NE");
            } else {
              System.out.println("NO");
            }
          } else if (Y < M) {
            if (X > N) {
              System.out.println("SE");
            } else {
              System.out.println("SO");
            }
          }
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}

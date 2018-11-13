#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int max = 0;
    while (n--) {
      int c;
      cin >> c;
      if (c > max) {
        max = c;
      }
    }
    cout << "Case " << t << ": " << max << "\n";
  }
  return 0;
}

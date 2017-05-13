#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long a, b;
    cin >> a >> b;
    char relation = (a < b) ? '<' : (a > b) ? '>' : '=';
    cout << relation << "\n";
  }
  return 0;
}

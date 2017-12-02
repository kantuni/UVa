#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    char rel = (a < b) ? '<' : (a > b) ? '>' : '=';
    cout << rel << "\n";
  }
  return 0;
}

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    char rel = (a < b) ? '<' : (a > b) ? '>' : '=';
    cout << rel << endl;
  }
  return 0;
}

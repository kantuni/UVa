#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    vector<int> s(3);
    cin >> s[0] >> s[1] >> s[2];
    sort(s.begin(), s.end());
    cout << "Case " << t << ": " << s[1] << endl;
  }
  return 0;
}

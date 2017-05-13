#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    vector<int> salaries(3);
    cin >> salaries[0] >> salaries[1] >> salaries[2];
    sort(begin(salaries), end(salaries));
    cout << "Case " << t << ": " << salaries[1] << "\n";
  }
  return 0;
}

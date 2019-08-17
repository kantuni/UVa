#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii coords;
unordered_map<string, double> memo;

double d(ii p1, ii p2) {
  return sqrt(
    pow(p2.second - p1.second, 2.0) + pow(p2.first - p1.first, 2.0)
  );
}

double c(vi cindex) {
  if (cindex.size() == 2) {
    return d(coords[cindex[0]], coords[cindex[1]]);
  }
  
  double min = 2000000;
  for (int i = 1; i < cindex.size(); i++) {
    vi temp;
    for (int j = 1; j < cindex.size(); j++) {
      if (j != i) {
        temp.push_back(cindex[j]);
      }
    }

    string key = "";
    for (int j = 0; j < temp.size(); j++) {
      key += to_string(temp[j]);
    }
    
    if (memo.find(key) == end(memo)) {
      memo[key] = c(temp);
    }
    
    double sum = d(coords[cindex[0]], coords[cindex[i]]) + memo[key];
    if (sum < min) {
      min = sum;
    }
  }
  return min;
}

int main() {
  int cn = 1;

  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    int count = n * 2;
    while (count--) {
      string name;
      int x, y;
      cin >> name >> x >> y;
      
      ii p = {x, y};
      coords.push_back(p);
    }
    
    vi cindex;
    for (int i = 0; i < coords.size(); i++) {
      cindex.push_back(i);
    }

    cout << fixed << setprecision(2);
    cout << "Case " << cn << ": ";
    cout << c(cindex) << endl;
    coords.clear();
    memo.clear();
    cn++;
  }
  return 0;
}

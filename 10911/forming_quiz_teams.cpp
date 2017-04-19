#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

unordered_map<string, double> memo;

double d(ii p1, ii p2) {
  return sqrt(
    pow(p2.second - p1.second, 2.0) + pow(p2.first - p1.first, 2.0)
  );
}

double c(vii coords) {
  cout << "coords: " << "\n";
  for (int i = 0; i < coords.size(); ++i) {
    printf("(%d, %d) ", coords[i].first, coords[i].second);
  }
  cout << "\n";
  
  if (coords.size() == 2) {
    return d(coords[0], coords[1]);
  }
  
  double min = 2000000;
  for (int i = 1; i < coords.size(); ++i) {
    vii temp;
    for (int j = 1; j < coords.size(); ++j) {
      if (j != i) {
        temp.push_back(coords[j]);
      }
    }
    
    cout << "temp: " << "\n";
    for (int i = 0; i < temp.size(); ++i) {
      printf("(%d, %d) ", temp[i].first, temp[i].second);
    }
    cout << "\n";
    
    double sum = d(coords[0], coords[i]) + c(temp);
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

    vii coords;
    int count = n * 2;
    
    while (count > 0) {
      string name;
      int x, y;
      cin >> name >> x >> y;
      
      ii p = {x, y};
      coords.push_back(p);
      --count;
    }

    cout << "Case " << cn << ": ";
    cout << fixed << setprecision(2) << c(coords) << "\n";
    ++cn;
  }
  
  return 0;
}


#include <iostream>
using namespace std;

int main() {
  int n, b, h, w;
  
  while (cin >> n >> b >> h >> w) {
    int mc = 2000001;
    int hc = h;
    while (hc--) {
      int p;
      cin >> p;
      
      int wc = w;
      while (wc--) {
        int a;
        cin >> a;
        
        if (a >= n) {
          int cost = p * n;
          if (cost < mc) {
            mc = cost;
          }
        }
      }
    }
    
    if (mc < b) {
      cout << mc << "\n";
    } else {
      cout << "stay home\n";
    }
  }
  return 0;
}

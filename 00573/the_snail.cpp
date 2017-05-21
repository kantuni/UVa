#include <iostream>
using namespace std;

int main() {
  int H, U, D, F;
  while (true) {
    cin >> H >> U >> D >> F;
    if (H == 0) {
      break;
    }
    
    // initial height, distance climbed,
    // height after climbing, height after sliding
    double IH = 0.0, DC = U, HAC = IH + DC, HAS = HAC - D;
    int day = 2;
    
    while (true) {
      IH = HAS;
      DC -= U * (F / 100.0);
      HAC = IH + DC;
      if (HAC >= H) {
        cout << "success on day " << day << "\n";
        break;
      }
      HAS = HAC - D;
      if (HAS < 0) {
        cout << "failure on day " << day << "\n";
        break;
      }
      ++day;
    }
  }
  return 0;
}

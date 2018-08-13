#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    vector<string> hand;
    int spades = 0, hearts = 0, diamonds = 0, clubs = 0;
    bool ss = false, hs = false, ds = false, cs = false;
    int points = 0;
    int additional = 0;  
    while (iss) {
      string card;
      iss >> card;
      hand.push_back(card);
      char rank = card[0];
      char suit = card[1];
      // 1
      if (rank == 'J') {
        points += 1;
      } else if (rank == 'Q') {
        points += 2;
      } else if (rank == 'K') {
        points += 3;
      } else if (rank == 'A') {
        points += 4;
      }
      if (suit == 'S') {
        spades++;
      } else if (suit == 'H') {
        hearts++;
      } else if (suit == 'D') {
        diamonds++;
      } else if (suit == 'C') {
        clubs++;
      }
    }
    for (int i = 0; i < hand.size(); i++) {
      string card = hand[i];
      char rank = card[0];
      char suit = card[1];
      if (rank == 'J') {
        // 4
        bool fourth = (suit == 'S' && spades <= 3);
        fourth = fourth || (suit == 'H' && hearts <= 3);
        fourth = fourth || (suit == 'D' && diamonds <= 3);
        fourth = fourth || (suit == 'C' && clubs <= 3);
        points = fourth ? points - 1 : points;
      } else if (rank == 'Q') {
        // 3
        bool third = (suit == 'S' && spades <= 2);
        third = third || (suit == 'H' && hearts <= 2);
        third = third || (suit == 'D' && diamonds <= 2);
        third = third || (suit == 'C' && clubs <= 2);
        points = third ? points - 1 : points;
        // stopped
        if (suit == 'S' && spades >= 3) ss = true;
        else if (suit == 'H' && hearts >= 3) hs = true;
        else if (suit == 'D' && diamonds >= 3) ds = true;
        else if (suit == 'C' && clubs >= 3) cs = true;
      } else if (rank == 'K') {
        // 2
        bool second = (suit == 'S' && spades == 1);
        second = second || (suit == 'H' && hearts == 1);
        second = second || (suit == 'D' && diamonds == 1);
        second = second || (suit == 'C' && clubs == 1);
        points = second ? points - 1 : points;
        // stopped
        if (suit == 'S' && spades >= 2) ss = true;
        else if (suit == 'H' && hearts >= 2) hs = true;
        else if (suit == 'D' && diamonds >= 2) ds = true;
        else if (suit == 'C' && clubs >= 2) cs = true;
      } else if (rank == 'A') {
        // stopped
        if (suit == 'S') ss = true;
        else if (suit == 'H') hs = true;
        else if (suit == 'D') ds = true;
        else if (suit == 'C') cs = true;
      }
    }
    // 5
    if (spades == 2) {
      additional++;
    }
    if (hearts == 2) {
      additional++;
    }
    if (diamonds == 2) {
      additional++;
    }
    if (clubs == 2) {
      additional++;
    }
    // 6
    if (spades == 1) {
      additional += 2;
    }
    if (hearts == 1) {
      additional += 2;
    }
    if (diamonds == 1) {
      additional += 2;
    }
    if (clubs == 1) {
      additional += 2;
    }
    // 7
    if (spades == 0) {
      additional += 2;
    }
    if (hearts == 0) {
      additional += 2;
    }
    if (diamonds == 0) {
      additional += 2;
    }
    if (clubs == 0) {
      additional += 2;
    }
    if (points + additional < 14) {
      cout << "PASS" << "\n";
    } else {
      bool stopped = ss && hs && ds && cs;
      if (points >= 16 && stopped) {
        cout << "BID NO-TRUMP" << "\n";
      } else {
        int maximum = max({spades, hearts, diamonds, clubs});
        if (maximum == spades) {
          cout << "BID S" << "\n";
        } else if (maximum == hearts) {
          cout << "BID H" << "\n";
        } else if (maximum == diamonds) {
          cout << "BID D" << "\n";
        } else if (maximum == clubs) {
          cout << "BID C" << "\n";
        }
      }
    }
  }
  return 0;
}

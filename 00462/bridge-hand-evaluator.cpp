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
        bool fourth = (suit == 'S' and spades <= 3);
        fourth = fourth or (suit == 'H' and hearts <= 3);
        fourth = fourth or (suit == 'D' and diamonds <= 3);
        fourth = fourth or (suit == 'C' and clubs <= 3);
        points = fourth ? points - 1 : points;
      } else if (rank == 'Q') {
        // 3
        bool third = (suit == 'S' and spades <= 2);
        third = third or (suit == 'H' and hearts <= 2);
        third = third or (suit == 'D' and diamonds <= 2);
        third = third or (suit == 'C' and clubs <= 2);
        points = third ? points - 1 : points;
        // stopped
        if (suit == 'S' and spades >= 3) {
          ss = true;
        } else if (suit == 'H' and hearts >= 3) {
          hs = true;
        } else if (suit == 'D' and diamonds >= 3) {
          ds = true;
        } else if (suit == 'C' and clubs >= 3) {
          cs = true;
        }
      } else if (rank == 'K') {
        // 2
        bool second = (suit == 'S' and spades == 1);
        second = second or (suit == 'H' and hearts == 1);
        second = second or (suit == 'D' and diamonds == 1);
        second = second or (suit == 'C' and clubs == 1);
        points = second ? points - 1 : points;
        // stopped
        if (suit == 'S' and spades >= 2) {
          ss = true;
        } else if (suit == 'H' and hearts >= 2) {
          hs = true;
        } else if (suit == 'D' and diamonds >= 2) {
          ds = true;
        } else if (suit == 'C' and clubs >= 2) {
          cs = true;
        }
      } else if (rank == 'A') {
        // stopped
        if (suit == 'S') {
          ss = true;
        } else if (suit == 'H') {
          hs = true;
        } else if (suit == 'D') {
          ds = true;
        } else if (suit == 'C') {
          cs = true;
        }
      }
    }
    // 5
    additional += spades == 2 ? 1 : 0;
    additional += hearts == 2 ? 1 : 0;
    additional += diamonds == 2 ? 1 : 0;
    additional += clubs == 2 ? 1 : 0;
    // 6
    additional += spades == 1 ? 2 : 0;
    additional += hearts == 1 ? 2 : 0;
    additional += diamonds == 1 ? 2 : 0;
    additional += clubs == 1 ? 2 : 0;
    // 7
    additional += spades == 0 ? 2 : 0;
    additional += hearts == 0 ? 2 : 0;
    additional += diamonds == 0 ? 2 : 0;
    additional += clubs == 0 ? 2 : 0;
    if (points + additional < 14) {
      cout << "PASS" << "\n";
    } else {
      bool stopped = ss and hs and ds and cs;
      if (points >= 16 and stopped) {
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

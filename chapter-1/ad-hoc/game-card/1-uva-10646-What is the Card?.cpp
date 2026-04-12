#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, count = 1; cin >> tcs;

  while (tcs--) {
    int y = 0;
    vector<string> pile;
    vector<string> hand;

    for (int i = 0; i < 52; i++) {
      string card; cin >> card;
      pile.push_back(card);
    }

    for (int i = 0; i < 25; i++) {
      string top = pile.back();
      hand.push_back(top);
      pile.pop_back();
    }

    for (int i = 0; i < 3; i++) {
      string top = pile.back();
      char ch = top[0];
      int x;

      if (ch >= '2' && ch <= '9') x = ch - '0';
      else x = 10;

      y += x;

      int toThrow = 1 + (10 - x);
      for (int j = 0; j < toThrow; j++) pile.pop_back();
    }

    for (int j = 0; j < 25; j++) {
      string topHand = hand.back();
      hand.pop_back();
      pile.push_back(topHand);
    }

    string ans = pile[y - 1];
    cout << "Case " << count++ << ": " << ans << "\n";
  }
}
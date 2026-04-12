#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, count = 1; cin >> tcs;

  while (tcs--) {
    vector<string> cards;

    int amountCard = 52;
    while (amountCard--) {
      string card; cin >> card;
      cards.push_back(card);
    }

    vector<string> hand;
    int amountHand = 25;
    while (amountHand--) {
      string card = cards.back();
      hand.push_back(card);
      cards.pop_back();
    }
    reverse(hand.begin(), hand.end());

    int y = 0;
    for (int i = 0; i < 3; i++) {
      string card = cards.back();
      cards.pop_back();

      int x;
      char ch = card[0];
      if (ch >= '2' && ch <= '9') x = ch - '0';
      else x = 10;

      y += x;

      int toThrow = 10 - x;
      for (int j = 0; j < toThrow; j++) cards.pop_back();
    }

    cards.insert(cards.end(), hand.begin(), hand.end());

    string ans = cards[y - 1];
    cout << "Case " << count++ << ": " << ans << "\n";
  }
}
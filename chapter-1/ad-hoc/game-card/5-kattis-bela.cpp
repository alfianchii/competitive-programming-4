#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_map<char, int> trumpMap = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 20},
    {'T', 10},
    {'9', 14},
    {'8', 0},
    {'7', 0}
  };
  unordered_map<char, int> nonTrumpMap = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 2},
    {'T', 10},
    {'9', 0},
    {'8', 0},
    {'7', 0}
  };

  int hands; char trump; cin >> hands >> trump;
  int tcs = hands * 4;

  int score = 0;
  while (tcs--) {
    string card; cin >> card;
    char number = card[0], suit = card[1];

    int point = trumpMap[number];
    if (suit != trump) point = nonTrumpMap[number];

    score += point;
  }

  cout << score << "\n";
}
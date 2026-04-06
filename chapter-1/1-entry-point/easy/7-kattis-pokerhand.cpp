#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> cards(5); int freq[256] = {0};
  for (int i = 0; i < cards.size(); i++) cin >> cards[i];

  for (string card : cards) freq[card[0]]++;

  int hi = 0;
  for (auto x : freq) hi = max(hi, x);

  cout << hi << "\n";
}
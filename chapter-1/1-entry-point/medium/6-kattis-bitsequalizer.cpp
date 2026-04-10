#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, count = 1; cin >> tcs;

  while (tcs--) {
    string s, t; cin >> s >> t;

    int zeroToOne = 0, oneToZero = 0, questionToOne = 0, questionToZero = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0' && t[i] == '1') zeroToOne++;
      else if (s[i] == '1' && t[i] == '0') oneToZero++;
      else if (s[i] == '?' && t[i] == '1') questionToOne++;
      else if (s[i] == '?' && t[i] == '0') questionToZero++;
    }

    int moves = 0;
    int swapPairs = min(oneToZero, zeroToOne);
    moves += swapPairs;
    zeroToOne -= swapPairs;
    oneToZero -= swapPairs;

    int questionForSwap = min(oneToZero, questionToOne);
    moves += questionForSwap;
    oneToZero -= questionForSwap;
    questionToOne -= questionForSwap;

    if (oneToZero > 0) {
      cout << "Case " << count++ << ": -1\n";
      continue;
    }

    moves += zeroToOne;
    moves += questionToOne + questionToZero;

    cout << "Case " << count++ << ": " << moves << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  int round; string answer, player;

  while (cin >> round >> answer >> player && round != -1) {
    bool guessed[26] = {};
    bool inAnswer[26] = {};

    cout << "Round " << round << "\n";
    int wrong = 0;
    for (char ch : answer) inAnswer[ch - 'a'] = true;
    for (char ch : player) {
      if (guessed[ch - 'a']) continue;
      else guessed[ch - 'a'] = true;

      if (!inAnswer[ch - 'a']) wrong++;
    }

    if (wrong == 0) cout << "You win.\n";
    else if (wrong < 7) cout << "You chickened out.\n";
    else if (wrong >= 7) cout << "You lose.\n";
  }
}
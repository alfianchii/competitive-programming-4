#include <bits/stdc++.h>

using namespace std;

int main() {
  int round; string answer, player;

  while (cin >> round && round != -1) {
    cin >> answer >> player;
    
    bool guessed[26] = {};
    bool inAnswer[26] = {};
    int remaining = 0;

    for (char ch : answer) {
      int idx = ch - 'a';

      if (!inAnswer[idx]) {
        inAnswer[idx] = true;
        remaining++;
      }
    }

    int wrong = 0;
    string result = "You chickened out.";
    for (char ch : player) {
      int idx = ch - 'a';

      if (guessed[idx]) continue;
      guessed[idx] = true;

      if (inAnswer[idx]) {
        remaining--;

        if (remaining == 0) {
          result = "You win.";
          break;
        }
      } else {
        wrong++;

        if (wrong == 7) {
          result = "You lose.";
          break;
        }
      }
    }

    cout << "Round " << round << "\n";
    cout << result << "\n";
  }
}
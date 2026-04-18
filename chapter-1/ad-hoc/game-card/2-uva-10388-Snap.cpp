#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    // STACK: pop-to-right
    // QUEUE: pop-to-left
    string jane, john; cin >> jane >> john;
    deque<char> janeDown, johnDown;
    deque<char> janeUp, johnUp;
    bool finish = false;
    for (char c : jane) janeDown.push_back(c);
    for (char c : john) johnDown.push_back(c);

    for (int i = 0; i < 1000; i++) {
      if (janeDown.empty()) {
        for (char card : janeUp) janeDown.push_front(card);
        janeUp.clear();
      }
      if (johnDown.empty()) {
        for (char card : johnUp) johnDown.push_front(card);
        johnUp.clear();
      }

      char janeCard = janeDown.front(); janeDown.pop_front();
      char johnCard = johnDown.front(); johnDown.pop_front();
      johnUp.push_front(johnCard);
      janeUp.push_front(janeCard);

      if (janeCard == johnCard) {
        int verdict = random() / 141 % 2;

        if (verdict == 0) {
          while (!johnUp.empty()) {
            janeUp.push_front(johnUp.back());
            johnUp.pop_back();
          }

          cout << "Snap! for Jane: ";
          for (char card : janeUp) cout << card;
          cout << "\n";
        }
        else if (verdict == 1) {
          while (!janeUp.empty()) {
            johnUp.push_front(janeUp.back());
            janeUp.pop_back();
          }

          cout << "Snap! for John: ";
          for (char card : johnUp) cout << card;
          cout << "\n";
        }
      }

      if (janeDown.empty() && janeUp.empty()) {
        cout << "John wins.\n";
        finish = true;
        break;
      } else if (johnDown.empty() && johnUp.empty()) {
        cout << "Jane wins.\n";
        finish = true;
        break;
      }
    }

    if (!finish) cout << "Keeps going and going ...\n";
    if (tcs) cout << "\n";
  }
}
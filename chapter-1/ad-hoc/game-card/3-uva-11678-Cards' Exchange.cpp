#include <bits/stdc++.h>

using namespace std;

const int MAX_CARD = 100001;

int main() {
  int a, b;

  while (cin >> a >> b && (a != 0 && b != 0)) {
    bool alice[MAX_CARD] = {false};
    bool betty[MAX_CARD] = {false};

    for (int i = 0; i < a; i++) {
      int card; cin >> card;
      alice[card] = true;
    }
    for (int i = 0; i < b; i++) {
      int card; cin >> card;
      betty[card] = true;
    }

    int aliceOnly = 0;
    int bettyOnly = 0;
    for (int i = 0; i < MAX_CARD; i++) {
      if (alice[i] && !betty[i]) aliceOnly++;
      else if (betty[i] && !alice[i]) bettyOnly++;
    }

    cout << min(aliceOnly, bettyOnly) << "\n";
  }
}
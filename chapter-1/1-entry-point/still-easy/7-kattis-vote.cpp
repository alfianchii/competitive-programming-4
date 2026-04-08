#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    int candidate, hi = -1e9, count = 0, total = 0;
    int candidates; cin >> candidates;
    vector<int> votes(candidates);

    for (int i = 0; i < candidates; i++) {
      cin >> votes[i];
      hi = max(votes[i], hi);
      total += votes[i];
    }

    for (int i = 0; i < candidates; i++) {
      if (votes[i] == hi) {
        count++;
        candidate = i + 1;
      }
    }

    if (count > 1) cout << "no winner\n";
    else if (hi > (total / 2)) cout << "majority winner " << candidate << "\n";
    else cout << "minority winner " << candidate << "\n";
  }
}
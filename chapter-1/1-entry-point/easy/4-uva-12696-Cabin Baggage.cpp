#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, sum = 0; cin >> tcs;

  while (tcs--) {
    double l, w, d, weight, total; cin >> l >> w >> d >> weight;
    total = l + w + d;
    bool size = (l <= 56 && w <= 45 && d <= 25) || (total <= 125);

    if (size && weight <= 7) {
      cout << 1 << "\n";
      sum++;
    } else cout << 0 << "\n";
  }

  cout << sum << "\n";
}
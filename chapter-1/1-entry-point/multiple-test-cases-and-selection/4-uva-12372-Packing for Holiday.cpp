#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, l, w, h, count = 1;

  cin >> tcs;
  while (tcs--) {
    cin >> l >> w >> h;
    cout << "Case " << count << ": ";

    if (l <= 20 && w <= 20 && h <= 20) cout << "good\n";
    else cout << "bad\n";

    count++;
  }
}
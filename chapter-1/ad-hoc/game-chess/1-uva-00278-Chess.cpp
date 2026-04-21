#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    char pawn; double m, n; cin >> pawn >> m >> n;

    double hi = 1e9;
    if (pawn == 'r' || pawn == 'Q') hi = min(m, n);
    else if (pawn == 'k') hi = ceil(m * n / 2);
    else if (pawn == 'K') hi = ceil(m / 2) * ceil(n / 2);

    cout << hi << "\n";
  }
}
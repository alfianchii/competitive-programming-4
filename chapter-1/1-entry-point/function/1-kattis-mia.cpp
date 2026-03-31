#include <bits/stdc++.h>

using namespace std;

int main() {
  int s1, s2, r1, r2, sRes, rRes;

  while (cin >> s1 >> s2 >> r1 >> r2) {
    if (s1 == 0 && s2 == 0 && r1 == 0 && r2 == 0) break;

    int sMax = max(s1, s2); int sMin = min(s1, s2);
    int rMax = max(r1, r2); int rMin = min(r1, r2);

    if (sMin == 1 && sMax == 2) sRes = 100;
    else if (sMin == sMax) sRes = 80 + sMax;
    else sRes = sMax * 10 + sMin;

    if (rMin == 1 && rMax == 2) rRes = 100;
    else if (rMin == rMax) rRes = 80 + rMax;
    else rRes = rMax * 10 + rMin;

    if (sRes > rRes) cout << "Player 1 wins.\n";
    else if (rRes > sRes) cout << "Player 2 wins.\n";
    else cout << "Tie.\n";
  }
}
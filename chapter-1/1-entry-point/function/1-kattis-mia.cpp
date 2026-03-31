#include <bits/stdc++.h>

using namespace std;

int main() {
  int s1, s2, r1, r2, sRes, rRes;

  while (cin >> s1 >> s2 >> r1 >> r2) {
    if (s1 == 0 && s2 == 0 && r1 == 0 && r2 == 0) break;

    if ((s1 == 1 && s2 == 2) || (s1 == 2 && s2 == 1)) sRes = 3;
    else if (s1 == s2) sRes = 2;
    else sRes = 1;

    if ((r1 == 1 && r2 == 2) || (r1 == 2 && r2 == 1)) rRes = 3;
    else if (r1 == r2) rRes = 2;
    else rRes = 1;

    if (sRes == rRes) {
      int highestS = max({s1, s2});
      int highestR = max({r1, r2});

      if (highestS > highestR) cout << "Player 1 wins.\n";
      else if (highestR > highestS) cout << "Player 2 wins.\n";
      else cout << "Tie.\n";
    }
    else if (sRes > rRes) cout << "Player 1 wins.\n";
    else if (rRes > sRes) cout << "Player 2 wins.\n";
  }
}
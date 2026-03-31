#include <bits/stdc++.h>

using namespace std;

int getScore(int hi, int lo) {
  if (lo == 1 && hi == 2) return 100;
  else if (lo == hi) return 80 + hi;
  else return hi * 10 + lo;
}

int main() {
  int s1, s2, r1, r2, sRes, rRes;

  while (cin >> s1 >> s2 >> r1 >> r2) {
    if (s1 == 0 && s2 == 0 && r1 == 0 && r2 == 0) break;

    int sMax = max(s1, s2); int sMin = min(s1, s2);
    int rMax = max(r1, r2); int rMin = min(r1, r2);

    sRes = getScore(sMax, sMin);
    rRes = getScore(rMax, rMin);

    if (sRes > rRes) cout << "Player 1 wins.\n";
    else if (rRes > sRes) cout << "Player 2 wins.\n";
    else cout << "Tie.\n";
  }
}
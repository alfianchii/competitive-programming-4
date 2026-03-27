#include <bits/stdc++.h>

using namespace std;

int main() {
  // x = B's value (when A is 0)
  // y = Y degree of B (when value of A increase one)
  double x, y, res;

  cin >> x >> y;

  if (y != 1) cout << fixed << setprecision(9) << (double)x / (1 - y);
  else if (x != 0 && y == 1) cout << "IMPOSSIBLE";
  else if (x == 0 && y == 1) cout << "ALL GOOD";
}
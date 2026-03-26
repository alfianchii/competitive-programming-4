#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs;
  cin >> tcs;

  double res = 0.0;
  while (tcs--) {
    double q, y;
    cin >> q >> y;
    res += q * y;
  }

  cout << fixed << setprecision(3) << res << "\n";
}
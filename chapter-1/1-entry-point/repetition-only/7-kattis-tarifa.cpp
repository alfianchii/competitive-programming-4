#include <bits/stdc++.h>

using namespace std;

int main() {
  int mb, n, res;

  cin >> mb >> n;
  res = mb;
  while (n--) {
    int p;
    cin >> p;

    res -= p;
    res += mb;
  }

  cout << res << "\n";
}
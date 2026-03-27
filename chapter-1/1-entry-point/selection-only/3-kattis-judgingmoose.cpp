#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, r, m;
  cin >> l >> r;
  m = max(l, r) * 2;

  if (l == 0 && r == 0) cout << "Not a moose";
  else if (l == r) cout << "Even " << l + r;
  else if (l != r) cout << "Odd " << m;
}
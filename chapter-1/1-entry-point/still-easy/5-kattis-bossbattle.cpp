#include <bits/stdc++.h>
using namespace std;

int main() {
  int pillars; cin >> pillars;

  if (pillars <= 3) cout << 1 << "\n";
  else cout << pillars - 2 << "\n";
}
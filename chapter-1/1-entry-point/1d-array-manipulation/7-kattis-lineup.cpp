#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;
  vector<string> names(tcs);
  for (int i = 0; i < tcs; i++) cin >> names[i];
  
  bool inc = true;
  bool dec = true;
  for (int i = 0; i < tcs - 1; i++) {
    if (names[i] > names[i + 1]) inc = false;
    if (names[i] <= names[i + 1]) dec = false;
  }

  if (inc) cout << "INCREASING";
  else if (dec) cout << "DECREASING";
  else cout << "NEITHER";
}
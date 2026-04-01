#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  int line[n]; line[0] = 1;

  for (int i = 1; i <= n - 1; i++) {
    int p; cin >> p;
    line[p + 1] = i + 1;
  }

  for (int person : line) cout << person << " ";
}
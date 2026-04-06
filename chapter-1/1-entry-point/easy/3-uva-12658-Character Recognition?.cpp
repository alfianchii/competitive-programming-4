#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<string> grid(5);
  for (int i = 0; i < 5; i++) cin >> grid[i];

  for (int i = 0; i < n; i++) {
    string pattern = "";
    for (int row = 0; row < 5; row++) pattern += grid[row].substr(i * 4, 3);

    if (pattern == ".*." ".*." ".*." ".*." ".*.") cout << 1;
    else if (pattern == "***" "..*" "***" "*.." "***") cout << 2;
    else if (pattern == "***" "..*" "***" "..*" "***") cout << 3;
  }

  cout << endl;
}
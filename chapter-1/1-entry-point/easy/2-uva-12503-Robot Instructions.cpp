#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    int x = 0;
    int n; cin >> n;
    vector<int> moves;

    for (int i = 0; i < n; i++) {
      string dir; cin >> dir;

      if (dir == "LEFT") {
        x--;
        moves.push_back(-1);
      } else if (dir == "RIGHT") {
        x++;
        moves.push_back(1);
      } else {
        string a; int idx; cin >> a >> idx;
        x += moves[idx - 1];
        moves.push_back(moves[idx - 1]);
      }
    }

    cout << x << "\n";
  }
}
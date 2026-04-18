#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x, y;

  while (cin >> a >> b >> c >> x >> y && (a || b || c || x || y)) {
    vector<int> princess = {a, b, c};
    sort(princess.begin(), princess.end());

    int answer = -1;
    for (int z = 1; z <= 52; z++) {
      if (z == a || z == b || z == c || z == x || z == y) continue;

      vector<int> prince = {x, y, z};
      sort(prince.begin(), prince.end());
      
      int princessWin = 0;
      vector<bool> used(3, false);
      for (int i = 0; i < 3; i++) {
        bool found = false;
        
        for (int j = 0; j < 3; j++) {
          if (!used[j] && princess[j] > prince[i]) {
            used[j] = true;
            princessWin++;
            found = true;
            break;
          }
        }

        if (!found) {
          for (int j = 0; j < 3; j++) {
            if (!used[j]) {
              used[j] = true;
              break;
            }
          }
        }
      }

      if (princessWin <= 1) {
        answer = z;
        break;
      }
    }

    cout << answer << "\n";
  }
}
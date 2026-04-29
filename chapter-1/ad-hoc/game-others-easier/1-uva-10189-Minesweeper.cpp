#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;

  int tcs = 1;
  while (cin >> n >> m && (n || m)) {
    vector<string> field(n);
    for (int i = 0; i < n; i++) cin >> field[i];

    if (tcs > 1) cout << "\n";
    cout << "Field #" << tcs << ":\n";

    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (field[row][col] == '*') cout << "*";
        else {
          // 0 1
          int count = 0;
          for (int dRow = -1; dRow <= 1; dRow++) { // 0
            for (int dCol = -1; dCol <= 1; dCol++) { // 0
              if (dRow == 0 && dCol == 0) continue;

              int nRow = row + dRow; // 0
              int nCol = col + dCol; // 1

              if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                if (field[nRow][nCol] == '*') count++;
              }
            }
          }

          cout << count;
        }
      }

      cout << "\n";
    }

    tcs++;
  }
}
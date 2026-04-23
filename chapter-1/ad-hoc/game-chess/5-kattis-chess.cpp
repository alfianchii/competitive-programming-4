#include <bits/stdc++.h>

using namespace std;

bool hasSameColor(int x1, int y1, int x2, int y2) {
  return (x1 + y1) % 2 == (x2 + y2) % 2;
}

bool hasSamePosition(int x1, int y1, int x2, int y2) {
  return x1 == x2 && y1 == y2;
}

bool isOneStep(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) == abs(y1 - y2);
}

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    char c1, c2; int r1, r2; cin >> c1 >> r1 >> c2 >> r2;

    int x1 = c1 - 'A' + 1; int y1 = r1;
    int x2 = c2 - 'A' + 1; int y2 = r2;

    if (!hasSameColor(x1, y1, x2, y2)) {
      cout << "Impossible\n";
      continue;
    }

    if (hasSamePosition(x1, y1, x2, y2)) {
      cout << "0" << " " << c1 << " " << r1 << "\n";
      continue;
    }

    if (isOneStep(x1, y1, x2, y2)) {
      cout << "1" << " " << c1 << " " << r1 << " " << c2 << " " << r2 << "\n";
      continue;
    }

    bool found = false;
    // x = 2, y = 5
    // x1 = 6, y1 = 1
    // x2 = 5, y1 = 8
    for (int x = 1; x <= 8; x++) {
      for (int y = 1; y <= 8; y++) {
        if (abs(x1 - x) == abs(y1 - y) && abs(x2 - x) == abs(y2 - y)) {
          // 6 - 2 = 4 steps
          // 1 - 5 = 4 steps
          // 5 - 2 = 3 steps
          // 8 - 5 = 3 steps
          char midCol = (x - 1) + 'A';
          int midRow = y;

          cout << "2" << " " << c1 << " " << r1 << " " << midCol << " " << midRow << " " << c2 << " " << r2 << "\n";
          found = true;
          break;
        }
      }

      if (found) break;
    }
  }
}
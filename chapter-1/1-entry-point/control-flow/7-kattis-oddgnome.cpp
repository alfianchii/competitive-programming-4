#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    int group; cin >> group;
    int pG; cin >> pG; group--;
    int king, count = 2;

    while (group--) {
      int cG; cin >> cG;

      if (pG + 1 == cG) pG = cG;
      else king = count;

      count++;
    }

    cout << king << "\n";
  }
}
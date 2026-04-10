#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, i, j, round = 0;
  
  while (cin >> n >> i >> j) {
    while (i != j) {
      i = (i + 1) / 2;
      j = (j + 1) / 2;
      round += 1;
    }

    cout << round << "\n";
  }
}
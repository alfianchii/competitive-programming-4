#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("3-uva-11614.in", "r", stdin);
  freopen("3-uva-11614.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    int w;
    long long row =0, currW = 0;

    cin >> w;

    for (int i = 0; i < w; i++) {
      for (int j = 0; j <= i; j++) {
        currW++;

        if (currW == w) {
          if (j == i) row++;

          printf("%lld\n", row);
          break;
        }
      }
      
      row++;

      if (currW == w) break;
    }
  }
}
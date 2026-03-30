#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  int sum = 0, count = 1;

  while (n--) {
    int b; cin >> b;

    if (b > 0) sum++;
    else sum--;

    if (n == 0) {
      cout << "Case " << count << ": " << sum << "\n";
      cin >> n;
      count++;
      sum = 0;

      continue;
    }
  }
}
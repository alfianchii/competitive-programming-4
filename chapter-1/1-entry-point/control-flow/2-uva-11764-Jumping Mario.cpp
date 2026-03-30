#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, count = 1;

  cin >> tcs;
  while(tcs--) {
    int n, c, low = 0, high = 0;

    cin >> n; n--;
    cin >> c;
    while(n--) {
      int j; cin >> j;

      if (c > j) high++;
      else if (c < j) low++;

      c = j;
    }

    cout << "Case " << count << ": ";
    cout << low << " " << high << "\n";
    
    count++;
  }
}
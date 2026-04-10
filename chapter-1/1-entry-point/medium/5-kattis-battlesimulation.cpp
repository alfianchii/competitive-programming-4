#include <bits/stdc++.h>

using namespace std;

int main() {
  string a; cin >> a;

  for (int i = 0; i < a.size(); i++) {
    if (i + 2 < a.size()) {
      if (
        a[i] != a[i + 1] &&
        a[i] != a[i + 2] &&
        a[i + 1] != a[i + 2]
      ) {
        cout << "C";
        i += 2;
        continue;
      }
    }

    if (a[i] == 'R') cout << "S";
    else if (a[i] == 'B') cout << "K";
    else if (a[i] == 'L') cout << "H";
  }
}
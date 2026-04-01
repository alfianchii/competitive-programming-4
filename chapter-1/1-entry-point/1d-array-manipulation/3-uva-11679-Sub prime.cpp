#include <bits/stdc++.h>

using namespace std;

int main() {
  int b, n;

  // B, N          -> 3 3
  // RESERVES (Ri) -> 1 1 1
  // DEBENTURE (1) -> 1 2 1
  // DEBENTURE (2) -> 2 3 2
  // DEBENTURE (3) -> 3 1 3
  while (cin >> b >> n && (b != 0 && n != 0)) {
    vector<int> reserves(b), in(b, 0), out(b, 0);
    for (int i = 0; i < b; i++) cin >> reserves[i];

    // 1 2 1
    // 2 3 2
    // 3 1 3
    // RESERVES: [1 1 1]
    // OUT:      [1 2 3]
    // IN:       [3 1 2]
    for (int i = 0; i < n; i++) {
      int debtor, creditor, value; cin >> debtor >> creditor >> value;
      out[debtor - 1] += value;
      in[creditor - 1] += value;
    }

    bool isValid = true;
    for (int i = 0; i < b; i++) {
      if (reserves[i] + in[i] < out[i]) {
        isValid = false;
        break;
      }
    }

    cout << (isValid ? "S" : "N") << "\n";
  }
}
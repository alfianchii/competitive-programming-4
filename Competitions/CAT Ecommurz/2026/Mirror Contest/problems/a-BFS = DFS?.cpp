#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  vector<long long> arr(t);
  for (int i = 0; i < t; i++) cin >> arr[i];

  long long comb = 1;
  for (int i = 1; i < t - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      comb *= 2;
      comb %= 998244353;
    }
  }

  cout << comb << "\n";
}
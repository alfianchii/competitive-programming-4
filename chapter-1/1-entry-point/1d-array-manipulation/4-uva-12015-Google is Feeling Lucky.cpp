#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  int counter = 1;
  while (tcs--) {
    vector<string> urls(10); vector<int> freqs(10);

    int hi = -1;
    for (int i = 0; i < 10; i++) {
      cin >> urls[i] >> freqs[i];
      hi = max(hi, freqs[i]);
    }

    vector<string> goodUrls;
    cout << "Case #" << counter << ":\n";
    for (int i = 0; i < 10; i++) {
      if (freqs[i] == hi) cout << urls[i] << "\n";
    }

    counter++;
  }
}
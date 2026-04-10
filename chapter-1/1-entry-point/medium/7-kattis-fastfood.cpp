#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs; cin >> tcs;

  while (tcs--) {
    int n, m; cin >> n >> m;

    vector<vector<int>> prizes;
    for (int i = 0; i < n; i++) {
      int prizeTotal; cin >> prizeTotal;

      vector<int> prize;
      for (int j = 0; j < prizeTotal; j++) {
        int num; cin >> num;
        prize.push_back(num);
      }

      int cash; cin >> cash;
      prize.push_back(cash);

      prizes.push_back(prize);
    }

    vector<int> stickers(m + 1);
    for (int i = 1; i <= m; i++) cin >> stickers[i];

    long long totalCash = 0;
    for (auto &prize : prizes) {
      int sz = prize.size(); sz--;
      int cash = prize.back();

      int lo = INT_MAX;
      for (int i = 0; i < sz; i++) {
        int type = prize[i];
        lo = min(lo, stickers[type]);
      }

      totalCash += (long long) lo * cash;
    }

    cout << totalCash << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  int line[n]; line[0] = 0;

  int p;
  int count = 1;
  while (cin >> p) {
    line[count] = p;
    count++;
  }

  int res[n]; res[0] = 1;
  for (int i = 1; i < n; i++) {
    int jimmy = line[0];
    int other = line[i] + 1;

    res[jimmy + other] = i + 1;
  }

  for (int item : res) cout << item << " ";
}
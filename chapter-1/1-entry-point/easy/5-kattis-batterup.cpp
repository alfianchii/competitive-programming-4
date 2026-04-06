#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  double sum = 0, denom = 0;

  while (n--) {
    double res; cin >> res;
    if (res != -1) {
      sum += res;
      denom++;
    }
  }

  cout << sum / denom << "\n";
}
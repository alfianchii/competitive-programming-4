#include <bits/stdc++.h>

using namespace std;

int getDigit(long long num, int loop = 1) {
  if (num == 1) return loop++;

  int digit = 0;
  while (num != 0) {
    num /= 10;
    digit++;
  }
  loop++;

  return getDigit(digit, loop);
}

int main() {
  long long x;

  while (cin >> x) {
    int res = getDigit(x);
    cout << res << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

int getDigit(int num) {
  if (num < 10) return num;

  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return getDigit(sum);
}

int main() {
  int n;

  while (cin >> n && n != 0) {
    cout << getDigit(n) << "\n";
  }
}
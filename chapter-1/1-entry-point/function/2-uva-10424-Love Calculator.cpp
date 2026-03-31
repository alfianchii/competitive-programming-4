#include <bits/stdc++.h>

using namespace std;

int getDigitRoot(int num) {
  if (num < 10) return num;

  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return getDigitRoot(sum);
}

int getValue(string name) {
  int sum = 0;
  
  for (int c : name) {
    if (c >= 97 && c <= 122) sum += (c - 97) + 1;
    else if (c >= 65 && c <= 90) sum += (c - 65) + 1;
    else continue;
  }

  return getDigitRoot(sum);
}

int main() {
  string name1, name2;

  while(getline(cin, name1), getline(cin, name2)) {
    int value1 = getValue(name1);
    int value2 = getValue(name2);

    double hi = max(value1, value2);
    double lo = min(value1, value2);

    double ratio = (lo / hi) * 100;

    cout << fixed << setprecision(2) << ratio << " %\n";
  }
}
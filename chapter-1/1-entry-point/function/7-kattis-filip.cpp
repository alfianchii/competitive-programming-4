#include <bits/stdc++.h>

using namespace std;

int getReversed(string str) {
  string res;
  int length = str.size() - 1;
  for (int i = length; i >= 0; i--) {
    res += str[i];
  }

  return stoi(res);
}

int main() {
  string a, b; cin >> a >> b;
  cout << max(getReversed(a), getReversed(b));
}
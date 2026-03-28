#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, a, b;
  char op;

  cin >> tcs;
  while (tcs--) {
    string str;
    cin >> str;

    if (str == "P=NP") cout << "skipped\n";
    else {
      stringstream ss(str);
      ss >> a >> op >> b;
      cout << a + b << "\n";
    }
  }
}
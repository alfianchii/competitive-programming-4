#include <bits/stdc++.h>

using namespace std;

int main() {
  int l;

  while (cin >> l && l != 0) {
    string dir = "+x";
    vector<string> bends(l - 1);
    for (int i = 0; i < l - 1; i++) cin >> bends[i];

    for (string bend : bends) {
      if (bend == "No") continue;

      if (dir == "+x") dir = bend;
      else if (dir == "-x") {
        if (bend[0] == '+') dir = "-" + bend.substr(1);
        else dir = "+" + bend.substr(1);
      }
      else if (dir == bend) dir = "-x";
      else {
        string opposite;
        if (bend[0] == '+') opposite = "-" + bend.substr(1);
        else opposite = "+" + bend.substr(1);

        if (dir == opposite) dir = "+x";
      }
    }

    cout << dir << "\n";
  }
}
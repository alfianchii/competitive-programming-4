#include <bits/stdc++.h>

using namespace std;

int main() {
  int sweet, sour;
  
  while (cin >> sweet >> sour && (sweet != 0 || sour != 0)) {
    if (sweet + sour == 13) cout << "Never speak again.\n";
    else if (sour > sweet) cout << "Left beehind.\n";
    else if (sweet > sour) cout << "To the convention.\n";
    else if (sweet == sour) cout << "Undecided.\n";
  }
}
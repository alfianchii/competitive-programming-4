#include <bits/stdc++.h>

using namespace std;

int main() {
  bool isValid = false;
  string letter; cin >> letter;

  for (int i = 0; i < letter.size(); i++) {
    if (letter[i] == 's' && letter[i + 1] == 's') isValid = true;
  }

  cout << (isValid ? "hiss" : "no hiss");
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  char s;
  string name;

  while (scanf("%c", &s) != EOF) {
    if (s != '\n') name += s;
  }

  cout << "Thank you, " << name << ", and farewell!";
}
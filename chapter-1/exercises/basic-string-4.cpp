#include <bits/stdc++.h>

using namespace std;

int main() {
  string word;
  vector<string> tokens;

  while (cin >> word) {
    string temp = "";
    for (char ch : word) {
      if (ch != ' ' && ch != '.') temp += tolower(ch);
    }
    tokens.push_back(temp);
  }

  sort(tokens.begin(), tokens.end());

  for (string token : tokens) {
    cout << token << "\n";
  }

  cout << "Smallest: " << tokens[0] << "\n";
}
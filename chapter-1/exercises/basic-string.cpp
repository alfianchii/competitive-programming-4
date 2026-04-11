#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> strs;

  string str;
  while (getline(cin, str)) {
    if (str.rfind(".......", 0) == 0) break;
    strs.push_back(str);
  }

  string words = "";
  for (int i = 0; i < strs.size(); i++) {
    if (i > 0) words += " ";
    words += strs[i];
  }

  cout << words << "\n";
}
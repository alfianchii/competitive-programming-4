#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, study, born, courses;
  string name, slash;

  cin >> tcs;
  while (tcs--) {
    cin >> name >> study >> slash;
    cin >> born >> slash;
    cin >> courses;

    cout << name << " ";
    if (study >= 2010 || born >= 1991) cout << "eligible\n";
    else if (courses > 40) cout << "ineligible\n";
    else cout << "coach petitions\n";
  }
}
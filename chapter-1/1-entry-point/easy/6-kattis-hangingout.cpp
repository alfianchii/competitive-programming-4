#include <bits/stdc++.h>

using namespace std;

int main() {
  int limit, events, people = 0, denied = 0; cin >> limit >> events;

  while (events--) {
    string status; int num; cin >> status >> num;

    int hold = people + num;
    if (status == "enter" && hold <= limit) people += num;
    else if (status == "leave") people -= num;
    else denied++;
  }

  cout << denied << "\n";
}
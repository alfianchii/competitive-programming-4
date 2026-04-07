#include <bits/stdc++.h>

using namespace std;

int main() {
  int teaTotal; cin >> teaTotal;
  vector<int> teas(teaTotal);
  for (int i = 0; i < teas.size(); i++) cin >> teas[i];

  int toppingTotal; cin >> toppingTotal;
  vector<int> toppings(toppingTotal);
  for (int i = 0; i < toppings.size(); i++) cin >> toppings[i];

  long long lowestPrice = 1e9;
  for (int i = 0; i < teaTotal; i++) {
    int num; cin >> num;

    while (num--) {
      int toppingIdx; cin >> toppingIdx; toppingIdx--;
      long long price = teas[i] + toppings[toppingIdx];
      lowestPrice = min(lowestPrice, price);
    }
  }

  long long money; cin >> money;
  int totalCup = money / lowestPrice;

  cout << (totalCup > 0 ? totalCup - 1 : 0) << "\n";
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tcs, n;
  
  cin >> tcs;
  while (tcs--) {
    cin >> n;
    
    if (n % 2 == 0) cout << n << " is even\n";
    else cout << n << " is odd\n";
  }
}
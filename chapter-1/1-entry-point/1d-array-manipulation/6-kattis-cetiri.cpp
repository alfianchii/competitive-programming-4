#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> temp(3);
  for (int i = 0; i < 3; i++) cin >> temp[i];

  int lo = min({temp[0], temp[1], temp[2]});
  int hi = max({temp[0], temp[1], temp[2]});

  int nums[3]; 
  nums[0] = lo;
  nums[2] = hi;
  nums[1] = temp[0] + temp[1] + temp[2] - lo - hi;

  int a = nums[1] - nums[0];
  int b = nums[2] - nums[1];

  if (a == b) cout << nums[2] + a;
  else if (a > b) cout << nums[0] + b;
  else cout << nums[1] + a;
}
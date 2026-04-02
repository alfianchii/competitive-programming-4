#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> temp; int nums[4]; memset(nums, 0, sizeof(nums));
  for (int i = 0; i < 3; i++) {
    int x; cin >> x; temp.push_back(x);
  }

  int lo = min({temp[0], temp[1], temp[2]});
  int hi = max({temp[0], temp[1], temp[2]});
  nums[0] = lo; nums[2] = hi;
  for (int t : temp) {
    if (t != lo && t != hi) nums[1] = t;
  }
  
  int a = nums[1] - nums[0];
  int b = nums[2] - nums[1];

  if (a != b) {
    int diff = (nums[2] - nums[0]) / 3;
    nums[3] = nums[2];
    nums[2] = nums[1] + diff;

    cout << nums[2];
  } else cout << nums[2] + a;
}
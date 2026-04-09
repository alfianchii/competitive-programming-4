#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t; cin >> n >> t;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  if (t == 1) cout << 7 << "\n";
  else if (t == 2) {
    if (arr[0] > arr[1]) cout << "Bigger\n";
    else if (arr[0] == arr[1]) cout << "Equal\n";
    else if (arr[0] < arr[1]) cout << "Smaller\n";
  } else if (t == 3) {
    int a = arr[0], b = arr[1], c = arr[2];
    cout << a + b + c - min({a, b, c}) - max({a, b, c}) << "\n";
  } else if (t == 4) {
    int sum = 0;
    for (int num : arr) sum += num;
    cout << sum << "\n";
  } else if (t == 5) {
    int sum = 0;
    for (int num : arr) {
      if (num % 2 == 0) sum += num;
    }
    cout << sum << "\n";
  } else if (t == 6) {
    string letter = "";
    for (int i = 0; i < arr.size(); i++) {
      int res = arr[i] % 26;
      letter += 'a' + res;
    }

    cout << letter << "\n";
  } else if (t == 7) {
    vector<bool> visited(arr.size(), false);

    int i = 0;
    while (true) {
      if (i < 0 || i >= arr.size()) {
        cout << "Out\n";
        break;
      }

      if (i == arr.size() - 1) {
        cout << "Done\n";
        break;
      }

      if (visited[i]) {
        cout << "Cyclic\n";
        break;
      }
      
      visited[i] = true;
      i = arr[i];
    }
  }
}
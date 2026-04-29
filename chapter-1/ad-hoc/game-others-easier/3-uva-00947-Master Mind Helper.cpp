#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFeedback(const string& guess, const string& code) {
  int correct = 0, freqGuess[10] = {0}, freqCode[10] = {0};

  for (int i = 0; i < guess.size(); i++) {
    if (guess[i] == code[i]) correct++;
    else {
      int g = guess[i] - '0';
      int c = code[i] - '0';

      freqGuess[g]++;
      freqCode[c]++;
    }
  }

  int wrong = 0;
  for (int digit = 1; digit <= 9; digit++) wrong += min(freqGuess[digit], freqCode[digit]);

  return {correct, wrong};
}

void generateCodes(int pos, int len, string& code, const string& guess, int right, int wrong, int& ans) {
  // 2 == 2
  if (pos == len) {
    // guess = 15, code = 11
    pair<int, int> feedback = getFeedback(guess, code);

    if (feedback.first == right && feedback.second == wrong) ans++;

    return;
  }

  // 15 -> len = 2
  // pos = 0, code = "" -> pos = 1, code = "1" -> pos = 2, code = "11"
  for (char digit = '1'; digit <= '9'; digit++) {
    code.push_back(digit);
    generateCodes(pos + 1, len, code, guess, right, wrong, ans);
    // 11 -> 1 (12, ..., ..., so forth)
    code.pop_back();
  }
}

int countPossibleCodes(const string& guess, int right, int wrong) {
  int ans = 0;
  string code = "";
  int len = guess.size();

  generateCodes(0, len, code, guess, right, wrong, ans);

  return ans;
}

int main() {
  int tcs; cin >> tcs;
  
  while (tcs--) {
    string guess; int right, wrong;
    cin >> guess >> right >> wrong;

    int ans = countPossibleCodes(guess, right, wrong);
    cout << ans << "\n";
  }
}
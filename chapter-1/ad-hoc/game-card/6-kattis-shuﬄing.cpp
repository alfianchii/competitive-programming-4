#include <bits/stdc++.h>

using namespace std;

int main() {
  int slot; string act; cin >> slot >> act;

  vector<int> originalDeck(slot);
  for (int i = 0; i < slot; i++) originalDeck[i] = i;
  vector<int> tempDeck = originalDeck;

  int count = 0;
  do {
    int div = slot / 2;

    if (slot % 2 == 0) {
      vector<int> left(div), right(div);
      for (int i = 0; i < div; i++) left[i] = tempDeck[i];
      for (int i = 0; i < div; i++) right[i] = tempDeck[i + div];

      int idx = 0;
      if (act == "out") {
        for (int i = 0; i < div; i++) {
          tempDeck[idx++] = left[i];
          tempDeck[idx++] = right[i];
        }
      } else if (act == "in") {
        for (int i = 0; i < div; i++) {
          tempDeck[idx++] = right[i];
          tempDeck[idx++] = left[i];
        }
      }
    } else {
      if (act == "out") {
        int leftDiv = div + 1; int rightDiv = div;

        vector<int> left(leftDiv), right(rightDiv);
        for (int i = 0; i < leftDiv; i++) left[i] = tempDeck[i];
        for (int i = 0; i < rightDiv; i++) right[i] = tempDeck[i + leftDiv];

        int idx = 0;
        for (int i = 0; i < rightDiv; i++) {
          tempDeck[idx++] = left[i];
          tempDeck[idx++] = right[i];
        }

        tempDeck[idx] = left.back();
      } else if (act == "in") {
        int leftDiv = div; int rightDiv = div + 1;

        vector<int> left(leftDiv), right(rightDiv);
        for (int i = 0; i < leftDiv; i++) left[i] = tempDeck[i];
        for (int i = 0; i < rightDiv; i++) right[i] = tempDeck[i + leftDiv];

        int idx = 0;
        for (int i = 0; i < leftDiv; i++) {
          tempDeck[idx++] = right[i];
          tempDeck[idx++] = left[i];
        }

        tempDeck[idx] = right.back();
      }
    }

    count++;
  } while (tempDeck != originalDeck);

  cout << count << "\n";
}
#include <bits/stdc++.h>

using namespace std;

void parse(const string &s, unordered_map<string, char> &mp) {
  stringstream ss(s);
  string pawn;
  
  while (getline(ss, pawn, ',')) {
    if (pawn.size() == 3) mp[pawn.substr(1)] = pawn[0];
    else mp[pawn] = 'P';
  }
}

bool isOdd(int num) {
  return num % 2 == 1;
}

bool isEven(int num) {
  return num % 2 == 0;
}

int main() {
  unordered_map<string, char> white, black;
  
  string temp, w, b;
  getline(cin, w); w = w.substr(7);
  getline(cin, b); b = b.substr(7);

  parse(w, white);
  parse(b, black);

  int boardRow = 8;
  for (int row = 1; row <= 17; row++) {
    int color;
    bool isSquare = true;

    if (isOdd(row / 2)) color = 1;
    else if (isEven(row / 2)) color = 2;

    for (int col = 1; col <= 8; col++) {
      char colName = 'a' + col - 1;

      if (isOdd(row)) {
        cout << "+---";
        if (col >= 8) cout << "+";

        isSquare = false;
        continue;
      } else if (isEven(row)) {
        cout << "|";
        string square, pawn = ""; pawn += colName; pawn += to_string(boardRow);
        if (white.count(pawn)) {
          char piece = white.count(pawn) ? toupper(white[pawn]) : '.';
          if (isOdd(color)) square = "." + string(1, piece) + ".";
          else square = ":" + string(1, piece) + ":";
        } else if (black.count(pawn)) {
          char piece = black.count(pawn) ? tolower(black[pawn]) : '.';
          if (isOdd(color)) square = "." + string(1, piece) + ".";
          else square = ":" + string(1, piece) + ":";
        } else {
          if (isOdd(color)) square = "...";
          else if (isEven(color)) square = ":::";
        }

        cout << square;

        if (col >= 8) cout << "|";

        color++;
        continue;
      }
    }

    if (isSquare) boardRow--;
    cout << "\n";
  }
}
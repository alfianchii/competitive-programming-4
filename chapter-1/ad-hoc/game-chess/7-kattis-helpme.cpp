#include <bits/stdc++.h>

using namespace std;

struct Piece {
  char type;
  char col;
  int row;
};

int getPriority(char c) {
  if (c == 'K') return 1;
  if (c == 'Q') return 2;
  if (c == 'R') return 3;
  if (c == 'B') return 4;
  if (c == 'N') return 5;
  return 6;
}

int main() {
  string board; vector<Piece> white, black;
  unordered_map<char, bool> whiteMap = { {'K', true}, {'Q', true}, {'R', true}, {'B', true}, {'N', true}, {'P', true} };
  unordered_map<char, bool> blackMap = { {'k', true}, {'q', true}, {'r', true}, {'b', true}, {'n', true}, {'p', true} };

  int row = 8;
  while (cin >> board) {
    if (board[0] == '+') continue;

    int col = 1;
    for (int i = 2; i < board.size(); i++) {
      char pawn = board[i];
      char color = board[i - 1];
      char colName = 'a' + col - 1;
      if (pawn == ':' || pawn == '.') {
        i += 3;
        col++;
        continue;
      }

      Piece p;
      p.type = toupper(pawn);
      p.col = colName;
      p.row = row;

      if (whiteMap[pawn]) white.push_back(p);
      if (blackMap[pawn]) black.push_back(p);

      i += 3;
      col++;
    }

    row--;
  }

  sort(white.begin(), white.end(), [](Piece a, Piece b) {
    if (getPriority(a.type) != getPriority(b.type)) return getPriority(a.type) < getPriority(b.type);
    if (a.row != b.row) return a.row < b.row;
    return a.col < b.col;
  });
  sort(black.begin(), black.end(), [](Piece a, Piece b) {
    if (getPriority(a.type) != getPriority(b.type)) return getPriority(a.type) < getPriority(b.type);
    if (a.row != b.row) return a.row > b.row;
    return a.col < b.col;
  });

  cout << "White: ";
  for (int i = 0; i < white.size(); i++) {
    if (white[i].type != 'P') cout << white[i].type;
    cout << white[i].col << white[i].row;
    if (i != white.size() - 1) cout << ",";
  }
  cout << "\n";

  cout << "Black: ";
  for (int i = 0; i < black.size(); i++) {
    if (black[i].type != 'P') cout << black[i].type;
    cout << black[i].col << black[i].row;
    if (i != black.size() - 1) cout << ",";
  }
  cout << "\n";
}
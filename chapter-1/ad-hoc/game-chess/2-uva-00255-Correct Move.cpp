#include <bits/stdc++.h>

using namespace std;

const int BOARD_SIZE = BOARD_SIZE;

bool boundaryBoardCheck(int nr, int nc) {
  return nr >= 0 && nr < BOARD_SIZE && nc >= 0 && nc < BOARD_SIZE;
}

bool isLegalQueenMove(int k, int q, int nq) {
  if (q == nq) return false;
  if (nq == k) return false;

  int rk = k / BOARD_SIZE; int ck = k % BOARD_SIZE;
  int rq = q / BOARD_SIZE; int cq = q % BOARD_SIZE;
  int rnq = nq / BOARD_SIZE; int cnq = nq % BOARD_SIZE;

  if (rq == rnq) {
    if (rk == rq && (ck > min(cq, cnq) && ck < max(cq, cnq))) return false;
  }
  else if (cq == cnq) {
    if (ck == cq && (rk > min(rq, rnq) && rk < max(rq, rnq))) return false;
  }
  else return false;

  return true;
}

bool isAllowedQueenMove(int k, int q, int nq) {
  int nr, nc, pos;
  int rk = k / BOARD_SIZE; int ck = k % BOARD_SIZE;

  nr = rk - 1; nc = ck;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos == nq) return false;
  }

  nr = rk + 1; nc = ck;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos == nq) return false;
  }

  nr = rk; nc = ck - 1;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos == nq) return false;
  }

  nr = rk; nc = ck + 1;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos == nq) return false;
  }

  return true;
}

bool kingHasValidMove(int k, int q, int nq) {
  int nr, nc, pos;
  int rk = k / BOARD_SIZE; int ck = k % BOARD_SIZE;
  int rnq = nq / BOARD_SIZE; int cnq = nq % BOARD_SIZE;

  nr = rk - 1; nc = ck;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos != nq && !(nr == rnq || nc == cnq)) return true;
  }

  nr = rk + 1; nc = ck;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos != nq && !(nr == rnq || nc == cnq)) return true;
  }

  nr = rk; nc = ck - 1;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos != nq && !(nr == rnq || nc == cnq)) return true;
  }

  nr = rk; nc = ck + 1;
  if (boundaryBoardCheck(nr, nc)) {
    pos = nr * BOARD_SIZE + nc;
    if (pos != nq && !(nr == rnq || nc == cnq)) return true;
  }

  return false;
}

int main() {
  int k, q, nq;

  while (cin >> k >> q >> nq) {
    if (k == q) {
      cout << "Illegal state\n";
      continue;
    }

    if (!isLegalQueenMove(k, q, nq)) {
      cout << "Illegal move\n";
      continue;
    }

    if (!isAllowedQueenMove(k, q, nq)) {
      cout << "Move not allowed\n";
      continue;
    }

    if (kingHasValidMove(k, q, nq)) {
      cout << "Continue\n";
      continue;
    } else {
      cout << "Stop\n";
      continue;
    }
  }
}
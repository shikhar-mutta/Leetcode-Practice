// Link: https://leetcode.com/problems/design-tic-tac-toe/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per move  SC: O(n)
// Approach: track running sums per row/col/diag/anti-diag for each player
// via +1/-1, a move wins when any line sum reaches +-n
class TicTacToe {
    vector<int> rows, cols;
    int diag = 0, anti = 0;
    int n;

public:
    TicTacToe(int n) : rows(n, 0), cols(n, 0), n(n) {}

    int move(int row, int col, int player) {
        int delta = player == 1 ? 1 : -1;
        rows[row] += delta;
        cols[col] += delta;
        if (row == col) diag += delta;
        if (row + col == n - 1) anti += delta;

        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(anti) == n) return player;
        return 0;
    }
};

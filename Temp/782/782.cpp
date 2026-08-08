// Link: https://leetcode.com/problems/transform-to-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: verify every row is either row0 or its complement (equivalently, board[i][j]^board[0][j]^board[i][0]^board[0][0]==0 for all cells). Check row0 and col0 have counts within 1 of n/2 (chessboard constraint). Count how many positions in row0/col0 are "wrong parity" (mismatch with expected alternating pattern); the swap count is half of min(wrong, n-wrong), separately for rows and columns, summed.
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((board[0][0]^board[i][0]^board[0][j]^board[i][j]) != 0) return -1;

        int rowSum = accumulate(board[0].begin(), board[0].end(), 0);
        int colSum = 0;
        for (int i = 0; i < n; i++) colSum += board[i][0];
        if (rowSum < n/2 || rowSum > (n+1)/2) return -1;
        if (colSum < n/2 || colSum > (n+1)/2) return -1;

        int rowSwap = 0, colSwap = 0;
        for (int i = 0; i < n; i++) {
            if (board[0][i] == (i % 2)) rowSwap++;
            if (board[i][0] == (i % 2)) colSwap++;
        }
        if (n % 2) {
            if (rowSwap % 2) rowSwap = n - rowSwap;
            if (colSwap % 2) colSwap = n - colSwap;
        } else {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        }
        return (rowSwap + colSwap) / 2;
    }
};

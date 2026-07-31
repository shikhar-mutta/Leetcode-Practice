// Link: https://leetcode.com/problems/transform-to-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(1)
// Approach: valid iff board[i][j] = board[0][0] XOR board[i][0] XOR
// board[0][j] for all cells (every row is row0 or its complement, same
// for columns). Row-sum and column-sum of the first row/col must each
// be n/2 (or (n+1)/2 if n odd). Count how many positions already match
// the target alternating parity pattern for rows and for columns; the
// number of swaps needed is half the mismatches (swaps fix 2 at a time),
// taking the smaller of matching-even vs matching-odd when n is even,
// or deriving the correct one when n is odd.
class Solution
{
public:
    int movesToChessboard(vector<vector<int>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0)
                    return -1;

        int rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < n; i++)
        {
            rowSum += board[0][i];
            colSum += board[i][0];
            if (board[i][0] == (i % 2))
                rowSwap++;
            if (board[0][i] == (i % 2))
                colSwap++;
        }
        if (rowSum < n / 2 || rowSum > (n + 1) / 2)
            return -1;
        if (colSum < n / 2 || colSum > (n + 1) / 2)
            return -1;

        if (n % 2 == 1)
        {
            if (rowSwap % 2 == 1)
                rowSwap = n - rowSwap;
            if (colSwap % 2 == 1)
                colSwap = n - colSwap;
        }
        else
        {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        }
        return (rowSwap + colSwap) / 2;
    }
};

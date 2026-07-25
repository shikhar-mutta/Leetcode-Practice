// Link: https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m * l) where n is the number of rows, m is the number of columns and l is the length of the word
    // SC: O(1) as we are not using any extra space
    // Approach:
    // 1. We will check for each cell in the board if we can place the word horizontally or vertically.
    // 2. We will check if the cell is empty or has the same character as the word.
    // 3. We will also check if the cell is at the boundary or has a '#' character.
    bool placehr(vector<vector<char>> &board, string &word, int i, int j,
                 int pos)
    {
        int n = board.size(), m = board[0].size();
        if (pos >= word.size())
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return true;
            return board[i][j] == '#';
        }
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (board[i][j] == ' ' || board[i][j] == word[pos])
        {
            return placehr(board, word, i, j + 1, pos + 1);
        }
        return false;
    }

    bool placedown(vector<vector<char>> &board, string &word, int i, int j,
                   int pos)
    {
        int n = board.size(), m = board[0].size();
        if (pos >= word.size())
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return true;
            return board[i][j] == '#';
        }
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (board[i][j] == ' ' || board[i][j] == word[pos])
        {
            return placedown(board, word, i + 1, j, pos + 1);
        }
        return false;
    }

    bool placeWordInCrossword(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        string rev = word;
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool down = false, right = false;
                if (i == 0 || (i - 1 >= 0 && board[i - 1][j] == '#'))
                    down = true;
                if (j == 0 || (j - 1 >= 0 && board[i][j - 1] == '#'))
                    right = true;
                if ((right && placehr(board, word, i, j, 0)) ||
                    (right && placehr(board, rev, i, j, 0)) ||
                    (down && placedown(board, word, i, j, 0)) ||
                    (down && placedown(board, rev, i, j, 0)))
                    return true;
            }
        }
        return false;
    }
};
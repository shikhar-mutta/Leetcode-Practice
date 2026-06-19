// Link: https://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool dfs(vector<vector<char>> &board, vector<vector<char>> &track, string &word, int i, int j, int ind)
    // {
    //     if (ind == (int)word.size())
    //         return true;
    //     if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || track[i][j] || board[i][j] != word[ind])
    //         return false;
    //     track[i][j] = 1;
    //     bool ans = dfs(board, track, word, i + 1, j, ind + 1) || dfs(board, track, word, i - 1, j, ind + 1) || dfs(board, track, word, i, j + 1, ind + 1) || dfs(board, track, word, i, j - 1, ind + 1);
    //     track[i][j] = 0;
    //     return ans;
    // }

    // bool exist(vector<vector<char>> &board, string word)
    // {

    //     vector<vector<char>> track(board.size(), vector<char>(board[0].size(), 0));
    //     for (int i = 0; i < (int)board.size(); i++)
    //         for (int j = 0; j < (int)board[0].size(); j++)
    //             if (dfs(board, track, word, i, j, 0)) // start matching from word[0]
    //                 return true;
    //     return false;
    // }

    int moveX[4] = {1, -1, 0, 0}; // down, up, right, left
    int moveY[4] = {0, 0, 1, -1}; // down, up, right, left
    int n, m;
    // TC: O(N * 3^L) where N is the number of cells in the board and L is the length of the word.
    // SC: O(L) where L is the length of the word.
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int idx)
    {
        if (idx == word.size() - 1) // Word is found
            return true;
        board[i][j] = '0'; // IMP: Mark the cell as visited
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = moveX[dir] + i;
            int ny = moveY[dir] + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                board[nx][ny] == word[idx + 1])
                if (dfs(board, nx, ny, word, idx + 1))
                    return true;
        }
        board[i][j] = word[idx]; // IMP: Restore the cell after backtracking
        return false;
    }

    bool exist(vector<vector<char>> &board, string &word)
    {
        n = board.size();                    // number of rows
        m = board[0].size();                 // number of columns
        unordered_map<char, int> boardCount; // count of each character in the board
        for (int row = 0; row < board.size(); ++row)
            for (int col = 0; col < board[0].size(); ++col)
                boardCount[board[row][col]]++;

        unordered_map<char, int> wordCount; // count of each character in the word
        for (char c : word)
        {
            wordCount[c]++;
            if (wordCount[c] > boardCount[c]) // IMP: Early Stop
                return false;
        }

        // 2. Reversal Optimisation
        // IMP--> first char has more cnt then last char --> reverse the word to reduce the search space
        if (boardCount[word.front()] > boardCount[word.back()])
            reverse(word.begin(), word.end());

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0]) // start matching from word[0]
                    if (dfs(board, i, j, word, 0))
                        return true;
        return false;
    }
};

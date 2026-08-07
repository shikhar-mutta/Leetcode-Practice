// Link: https://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*4^L)  SC: O(L) recursion depth
// Approach: DFS backtracking from every cell, marking visited in place and restoring after
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int,int,int)> dfs = [&](int r, int c, int idx) -> bool {
            if (idx == (int)word.size()) return true;
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) return false;
            char tmp = board[r][c];
            board[r][c] = '#';
            bool found = dfs(r+1,c,idx+1) || dfs(r-1,c,idx+1) || dfs(r,c+1,idx+1) || dfs(r,c-1,idx+1);
            board[r][c] = tmp;
            return found;
        };
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (dfs(r, c, 0)) return true;
        return false;
    }
};

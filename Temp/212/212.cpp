// Link: https://leetcode.com/problems/word-search-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*4^L)  SC: O(sum of word lengths)
// Approach: Trie of all words, per-cell backtracking DFS marking visited '#' and clearing the
// TrieNode's word on match to dedupe repeated finds
struct TrieNode {
    TrieNode* children[26] = {};
    string word;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (auto& w : words) {
            TrieNode* node = &root;
            for (char c : w) {
                int i = c - 'a';
                if (!node->children[i]) node->children[i] = new TrieNode();
                node = node->children[i];
            }
            node->word = w;
        }
        int m = board.size(), n = board[0].size();
        vector<string> res;
        function<void(int,int,TrieNode*)> dfs = [&](int r, int c, TrieNode* node) {
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '#') return;
            char ch = board[r][c];
            TrieNode* nxt = node->children[ch - 'a'];
            if (!nxt) return;
            if (!nxt->word.empty()) { res.push_back(nxt->word); nxt->word.clear(); }
            board[r][c] = '#';
            dfs(r+1,c,nxt); dfs(r-1,c,nxt); dfs(r,c+1,nxt); dfs(r,c-1,nxt);
            board[r][c] = ch;
        };
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                dfs(r, c, &root);
        return res;
    }
};

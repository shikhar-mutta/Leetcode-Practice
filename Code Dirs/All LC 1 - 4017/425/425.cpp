// Link: https://leetcode.com/problems/word-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26 * len)  SC: O(n * len)
// Approach: backtrack building rows one at a time; at each step the next
// row's required prefix is determined by the column formed so far, use a
// prefix->words map for fast lookup
class Solution {
    unordered_map<string, vector<string>> prefixMap;
    int len;
    vector<vector<string>> res;

    void backtrack(vector<string>& square) {
        int idx = square.size();
        if (idx == len) { res.push_back(square); return; }

        string prefix;
        for (auto& w : square) prefix += w[idx];

        for (auto& cand : prefixMap[prefix]) {
            square.push_back(cand);
            backtrack(square);
            square.pop_back();
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        len = words[0].size();
        for (auto& w : words) {
            for (int i = 1; i <= len; i++) prefixMap[w.substr(0, i)].push_back(w);
        }
        for (auto& w : words) {
            vector<string> square{w};
            backtrack(square);
        }
        return res;
    }
};

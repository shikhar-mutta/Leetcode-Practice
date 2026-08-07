// Link: https://leetcode.com/problems/keyboard-row/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of word lengths)  SC: O(1)
// Approach: map each letter to its keyboard row, check every letter in a
// word maps to the same row as the first letter
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int rowOf[26];
        for (int r = 0; r < 3; r++)
            for (char c : rows[r]) rowOf[c - 'a'] = r;

        vector<string> res;
        for (auto& w : words) {
            int row = rowOf[tolower(w[0]) - 'a'];
            bool ok = true;
            for (char c : w) if (rowOf[tolower(c) - 'a'] != row) { ok = false; break; }
            if (ok) res.push_back(w);
        }
        return res;
    }
};

// Link: https://leetcode.com/problems/generalized-abbreviation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)  SC: O(2^n)
// Approach: backtrack over each char, choosing to keep it (flush any pending
// abbreviation count) or abbreviate it (increment count)
class Solution {
    vector<string> res;

    void backtrack(const string& word, int i, string cur, int count) {
        if (i == (int)word.size()) {
            if (count > 0) cur += to_string(count);
            res.push_back(cur);
            return;
        }
        // abbreviate this char
        backtrack(word, i + 1, cur, count + 1);
        // keep this char
        string next = cur;
        if (count > 0) next += to_string(count);
        next += word[i];
        backtrack(word, i + 1, next, 0);
    }

public:
    vector<string> generateAbbreviations(string word) {
        backtrack(word, 0, "", 0);
        return res;
    }
};

// Link: https://leetcode.com/problems/concatenated-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum(len^2))  SC: O(sum(len))
// Approach: put all words in a set; for each word, DP word-break check
// using only OTHER dictionary words (require at least 2 parts)
class Solution {
    bool canBreak(const string& word, unordered_set<string>& dict) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = (i == n ? 1 : 0); j < i; j++) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (auto& w : words) {
            if (!w.empty() && canBreak(w, dict)) res.push_back(w);
        }
        return res;
    }
};

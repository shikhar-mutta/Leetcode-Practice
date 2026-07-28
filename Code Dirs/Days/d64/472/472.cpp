// Link: https://leetcode.com/problems/concatenated-words/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum(len^2))  SC: O(sum(len))
// Approach: put all words in a hash set, then for each word run a DP
// word-break check (dp[i] = true if prefix of length i can be split
// into >=1 other dictionary words) requiring at least two parts.
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for (auto& w : words) {
            int n = w.size();
            if (n == 0) continue;
            vector<int> dp(n + 1, -1);
            dp[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] == -1) continue;
                    string part = w.substr(j, i - j);
                    if (i - j == n) continue; // must use at least 2 parts
                    if (dict.count(part)) { dp[i] = dp[j] + 1; break; }
                }
            }
            if (dp[n] >= 1) ans.push_back(w);
        }
        return ans;
    }
};

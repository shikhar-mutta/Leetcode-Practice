// Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hamming1(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && hamming1(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[best]) best = i;
        }
        vector<string> res;
        for (int cur = best; cur != -1; cur = parent[cur]) res.push_back(words[cur]);
        reverse(res.begin(), res.end());
        return res;
    }
};

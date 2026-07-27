// Link: https://leetcode.com/problems/find-maximum-removals-from-source-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m), SC: O(m)
// Approach: dp[j] = minimum number of targetIndices positions that must be
// KEPT (not removed) among source characters used to match pattern[0..j]
// as a subsequence ending exactly at pattern index j. Scanning source left
// to right, for each character matching some pattern position(s) j
// (processed largest-to-smallest to avoid same-step reuse), extend
// dp[j] from dp[j-1], adding 1 if this source index is a target index
// being kept (canRemove flag is really "cost to keep", named oppositely).
// Answer is sz (total target indices) minus the minimal keep-cost for
// matching the full pattern.
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        int sz = targetIndices.size();
        unordered_map<char, vector<int>> mp;
        for (int i = m - 1; i >= 0; --i) {
            mp[pattern[i]].push_back(i);
        }
        vector<int> dp(m, INT_MAX);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int canRemove = 0;
            if (k < sz && targetIndices[k] == i) {
                canRemove = 1;
                k++;
            }
            char sc = source[i];
            if (!mp.count(sc)) {
                continue;
            }
            for (int j : mp[sc]) {
                if (j == 0) {
                    dp[0] = min(dp[0], canRemove);
                } else if (dp[j - 1] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - 1] + canRemove);
                }
            }
        }
        return sz - dp[m - 1];
    }
};

// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs[0].size();
        int n = strs.size();
        vector<int> dp(cols, 1);
        int best = 1;
        for (int j = 1; j < cols; j++) {
            for (int i = 0; i < j; i++) {
                bool valid = true;
                for (int r = 0; r < n; r++) {
                    if (strs[r][i] > strs[r][j]) { valid = false; break; }
                }
                if (valid) dp[j] = max(dp[j], dp[i] + 1);
            }
            best = max(best, dp[j]);
        }
        return cols - best;
    }
};

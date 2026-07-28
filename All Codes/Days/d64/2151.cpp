// Link: https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^n * n^2)  SC: O(1)
// Approach: brute force all 2^n subsets as candidate "good" sets. For each
// subset, verify every good person's statements are all consistent with
// the assumed good/bad labeling (statement 0=bad,1=good,2=unknown/ignore).
// Track max popcount among valid subsets.
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int best = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            bool valid = true;
            for (int i = 0; i < n && valid; i++) {
                if (!((mask >> i) & 1)) continue;
                for (int j = 0; j < n && valid; j++) {
                    int s = statements[i][j];
                    if (s == 2) continue;
                    int isGood = (mask >> j) & 1;
                    if (s != isGood) valid = false;
                }
            }
            if (valid) best = max(best, __builtin_popcount(mask));
        }
        return best;
    }
};

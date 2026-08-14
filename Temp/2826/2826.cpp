// Link: https://leetcode.com/problems/sorting-three-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int dp[4] = {0, 0, 0, 0};
        for (int x : nums) {
            int ndp[4];
            for (int j = 1; j <= 3; j++) {
                int best = INT_MAX;
                for (int p = 1; p <= j; p++) best = min(best, dp[p]);
                ndp[j] = best + (x == j ? 0 : 1);
            }
            for (int j = 1; j <= 3; j++) dp[j] = ndp[j];
        }
        return min({dp[1], dp[2], dp[3]});
    }
};

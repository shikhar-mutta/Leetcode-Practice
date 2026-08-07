// Link: https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sum)  SC: O(sum)
// Approach: reduces to subset-sum: let P = positive subset sum, then
// P - (total-P) = target => P = (total+target)/2; count subsets summing to P
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        int P = (total + target) / 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int t = P; t >= x; t--) dp[t] += dp[t - x];
        }
        return dp[P];
    }
};

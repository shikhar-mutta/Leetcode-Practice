// Link: https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long dp[2];
        dp[nums[0] % 2] = nums[0];
        dp[1 - nums[0] % 2] = LLONG_MIN;

        for (int i = 1; i < (int)nums.size(); i++) {
            int p = nums[i] % 2;
            long long same = dp[p] + nums[i];
            long long diff = (dp[1-p] == LLONG_MIN) ? LLONG_MIN : dp[1-p] + nums[i] - x;
            dp[p] = max(dp[p], max(same, diff));
        }
        return max(dp[0], dp[1]);
    }
};

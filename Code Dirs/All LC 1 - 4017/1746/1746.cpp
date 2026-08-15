// Link: https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        long long dp1 = 0, dp2 = 0;
        long long best = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            long long sq = (long long)nums[i] * nums[i];
            long long ndp2 = max({sq, dp1 + sq, dp2 + nums[i]});
            long long ndp1 = max((long long)nums[i], dp1 + nums[i]);
            dp1 = ndp1;
            dp2 = ndp2;
            best = max(best, dp2);
        }
        return (int)best;
    }
};

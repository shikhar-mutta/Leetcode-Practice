// Link: https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long dp0 = nums[0], dp1 = LLONG_MIN / 2;
        for (int i = 1; i < n; i++) {
            long long ndp0 = max(dp0, dp1) + nums[i];
            long long ndp1 = dp0 - nums[i];
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return max(dp0, dp1);
    }
};

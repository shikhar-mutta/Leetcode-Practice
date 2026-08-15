// Link: https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static long long prefixNum[1000];
    static long long dp[1001];

public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        prefixNum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixNum[i] = prefixNum[i - 1] + nums[i];
        }
        long long suffixCost = 0;
        memset(dp, 0x00, sizeof(dp[0]) * (n + 1));
        long long mindp = 0;
        for (int l = n - 1; l >= 0; --l) {
            dp[l] = (prefixNum[l] + k) * cost[l] + k * suffixCost + mindp;
            mindp = dp[l];
            for (int r = l + 1; r < n; ++r) {
                dp[r] += (prefixNum[r] + k) * cost[l];
                mindp = min(dp[r], mindp);
            }
            suffixCost += cost[l];
        }

        return mindp;
    }
};

long long Solution::prefixNum[1000];
long long Solution::dp[1001];

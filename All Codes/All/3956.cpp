// Link: https://leetcode.com/problems/maximum-sum-of-m-non-overlapping-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * (r - l + 1))  SC: O(n * m)
// Approach: We can use dynamic programming to solve this problem. We can maintain a dp array where dp[i][j] represents the maximum sum we can get by selecting j subarrays from the first i elements of the nums array. We can iterate through the nums array and for each element, we can check if we can form a subarray of length between l and r. If we can, we update the dp array accordingly. Finally, we return the maximum value in the dp array for m subarrays.
class Solution
{
public:
    long long maximumSum(vector<int> &nums, int m, int l, int r)
    {
        int n = nums.size();
        // cout << n << endl;
        int count = 0;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                total += nums[i];
                count++;
            }
        }
        if (l == 1 && count > 0 && count <= m)
            return total;
        vector<long long> presum(n + 1);
        for (int i = 0; i < n; i++)
        {
            presum[i + 1] = presum[i] + nums[i];
        }
        long long ret = LLONG_MIN / 3;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN / 3)); // 第i位为第j段结尾的sum值
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                for (int k = 0; k <= min(m - 1, i / l); k++)
                {
                    dp[i][k] = max(dp[i - 1][k], dp[i][k]);
                }
            }
            for (int j = l; j <= r; j++)
            {
                if (i + j > n)
                    break;
                if (presum[i + j] - presum[i] <= 0)
                {
                    dp[i + j][1] = max(dp[i + j][1], presum[i + j] - presum[i]);
                    ret = max(ret, dp[i + j][1]);
                    continue;
                }
                for (int k = 0; k <= min(m - 1, i / l); k++)
                {
                    dp[i + j][k + 1] = max(dp[i + j][k + 1], dp[i][k] + presum[i + j] - presum[i]);
                    ret = max(ret, dp[i + j][k + 1]);
                }
            }
        }
        return ret;
    }
};

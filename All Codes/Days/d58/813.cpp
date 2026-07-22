// Link: https://leetcode.com/problems/largest-sum-of-averages/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * k), SC: O(n * k)
    //  Approach: DP + Prefix Sum
    // 1. Create a prefix sum array to store the cumulative sum of the input array.
    // 2. Create a 2D DP array to store the maximum sum of averages for each subarray and number of partitions.
    // 3. Use a recursive function to calculate the maximum sum of averages for each subarray and number of partitions.
    // 4. Return the maximum sum of averages for the entire array and k partitions.
    double solve(vector<int> &prefix, int k, int i, vector<vector<double>> &dp)
    {
        int n = prefix.size() - 1;
        if (dp[i][k] != -1.0)
            return dp[i][k];
        if (k == 1)
        {
            return dp[i][k] =
                       (double)(prefix[n] - prefix[i]) / (n - i);
        }

        double ans = 0.0;

        for (int j = i; j <= n - k; j++)
        {
            double avg =
                (double)(prefix[j + 1] - prefix[i]) / (j - i + 1);

            ans = max(ans, avg + solve(prefix, k - 1, j + 1, dp));
        }

        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1.0));
        return solve(prefix, k, 0, dp);
    }
};
// Link: https://leetcode.com/problems/longest-arithmetic-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n*1001)
    //  Approach: Dynamic Programming
    //  1. Create a 2D array dp where dp[i][d] represents the length of the longest arithmetic subsequence ending at index i with a common difference d.
    //  2. Iterate through the array nums using two nested loops. The outer loop iterates through each element of nums, and the inner loop iterates through all previous elements to calculate the common difference.
    //  3. For each pair of indices (i, j), calculate the common difference d = nums[i] - nums[j]. Update dp[i][d] = dp[j][d] + 1, which means that the length of the longest arithmetic subsequence ending at index i with difference d is one more than the length of the subsequence ending at index j with the same difference.
    //  4. Keep track of the maximum length of the arithmetic subsequence found so far and return it at the end.
    int longestArithSeqLength(vector<int> &nums)
    {
        const int n{static_cast<int>(nums.size())};
        static short dp[1001000];
        memset(dp, 0, sizeof(short) * n * 1001);
        int res{2};
        for (int i{1}; i < n; ++i)
        {
            for (int j{0}; j < i; ++j)
            {
                int dif{nums[i] - nums[j] + 500};
                int iIdx{i * 1001 + dif}, jIdx{j * 1001 + dif};
                dp[iIdx] = dp[jIdx] + 1;
                res = max(res, dp[iIdx] + 1);
            }
        }
        return res;
    }
};
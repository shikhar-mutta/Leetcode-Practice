// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
//  Approach: We can use dynamic programming to solve this problem. We can keep track of the longest increasing subsequence (LIS) of the columns that we can keep. We can iterate through each column and check if we can keep it or not. If we can keep it, we can update the LIS accordingly. The answer will be the total number of columns minus the length of the LIS.
class Solution
{
public:
    int solve(int lastCol, vector<string> &strs, vector<int> &dp)
    {
        if (lastCol >= (strs[0].size() - 1))
            return 0;

        int nextCol = lastCol + 1;
        bool flag = true;
        int ans = 0;
        if (dp[lastCol] != -1)
            return dp[lastCol];
        for (int j = lastCol + 1; j < strs[0].size(); j++)
        {
            flag = true;
            for (int i = 0; i < strs.size(); i++)
            {
                if (strs[i][j] < strs[i][lastCol])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans = max(ans, 1 + solve(j, strs, dp));
            }
        }
        // ans=max(ans,solve(lastCol+1,strs,dp));
        return dp[lastCol] = ans;
    }
    int minDeletionSize(vector<string> &strs)
    {
        vector<int> dp(strs[0].size(), -1);
        int lis = 0;
        int n = strs[0].size();
        for (int i = 0; i < n; i++)
            lis = max(lis, 1 + solve(i, strs, dp));

        return n - lis;
    }
};
// Link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*K)  SC: O(N)
// Approach: Tabulation
class Solution
{
public:
    int f(int i, vector<int> &arr, int k, vector<int> &dp)
    {
        if (i == arr.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = i; j < min(i + k, (int)arr.size()); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + f(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for (int j = ind; j < min(ind + k, (int)arr.size()); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};
// Link: https://leetcode.com/problems/best-sightseeing-pair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array.
    // SC: O(n) as we are using extra space for dp array.
    // Approach:
    //  1. We will create a dp array of size n where dp[i] will store the maximum value of val[j]-j for j>i.
    //  2. We will iterate from n-2 to 0 and for each i, we will update dp[i]
    //  3. We will iterate from 0 to n-2 and for each i, we will calculate the maximum value of dp[i+1]+val[i]+i and update the answer.
    //  4. Finally we will return the answer.
    int maxScoreSightseeingPair(vector<int> &val)
    {
        int n = val.size();
        // to compute max of val val[j]-j;
        vector<int> dp(n);
        dp[n - 1] = val[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], val[i] - i);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(dp[i + 1] + val[i] + i, ans);
        }
        return ans;
    }
};
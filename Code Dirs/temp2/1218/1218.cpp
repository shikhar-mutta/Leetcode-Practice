// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const int OFFSET = 10000;

    int longestSubsequence(vector<int> &arr, int difference)
    {
        vector<int> dp(20001, 0);
        int ans = 1;

        for (int x : arr)
        {
            int prev = x - difference;
            if (prev >= -10000 && prev <= 10000)
                dp[x + OFFSET] = dp[prev + OFFSET] + 1;
            else
                dp[x + OFFSET] = 1;
            ans = max(ans, dp[x + OFFSET]);
        }
        return ans;
    }
};
// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input array arr
// SC: O(1) as we are using a fixed size array of 20001
// Approach:
// 1. We will use a dynamic programming approach to find the longest arithmetic subsequence of given difference in the input array arr.
// 2. We will create a dp array of size 20001 to store the length of the longest arithmetic subsequence ending at each index of arr.
// 3. We will iterate through the input array arr and for each element x, we will check if there exists a previous element prev = x - difference in the dp array. If it exists, we will update the length of the longest arithmetic subsequence ending at index x as dp[x + OFFSET] = dp[prev + OFFSET] + 1. If it does not exist, we will set dp[x + OFFSET] = 1.
// 4. We will keep track of the maximum length of the longest arithmetic subsequence found so far and return it as the final result.
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
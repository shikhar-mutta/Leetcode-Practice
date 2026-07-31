// Link: https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * maxVal) SC: O(maxVal^2)
//  Approach: value-indexed DP. dp[v][d] = longest subsequence ending in
//  value v whose last adjacent difference is exactly d; suf[v][d] is the
//  suffix max of dp[v][*] over diffs >= d (since the next diff must be
//  <= the previous one). For each new element x, try extending from
//  suf[x-d][d] and suf[x+d][d] for every candidate diff d, then merge the
//  results back into dp[x]/suf[x].
class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int dp[301][301] = {0}, res = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            int num = nums[i];
            for (int diff = 299; diff >= 0; --diff)
            {
                int L = 0, R = 0;
                if (num + diff < 301)
                    L = dp[num + diff][diff];
                if (num - diff > 0)
                    R = dp[num - diff][diff];
                dp[num][diff] = max(dp[num][diff + 1], 1 + max(L, R));
                res = max(res, dp[num][diff]);
            }
        }
        return res;
    }
};
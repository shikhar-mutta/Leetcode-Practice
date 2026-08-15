// Link: https://leetcode.com/problems/sum-of-good-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * maxVal), SC: O(maxVal)
// Approach: process elements left to right, tracking per-value cnt[v] (number of good
// subsequences seen so far ending in value v) and sum[v] (sum of their total-sums). For a new
// element x, it can start a fresh subsequence, or extend any subsequence ending in x-1 or x+1
// (values differing by exactly 1); each extension adds x to that subsequence's total. Accumulate
// the new sum contribution into the running answer.
class Solution
{
public:
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        const long long MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(maxVal + 2, 0), sum(maxVal + 2, 0);

        long long ans = 0;
        for (int x : nums)
        {
            long long newCount = 1;
            long long newSum = x;
            if (x - 1 >= 0)
            {
                newCount = (newCount + cnt[x - 1]) % MOD;
                newSum = (newSum + sum[x - 1] + cnt[x - 1] * x) % MOD;
            }
            if (x + 1 <= maxVal)
            {
                newCount = (newCount + cnt[x + 1]) % MOD;
                newSum = (newSum + sum[x + 1] + cnt[x + 1] * x) % MOD;
            }
            cnt[x] = (cnt[x] + newCount) % MOD;
            sum[x] = (sum[x] + newSum) % MOD;
            ans = (ans + newSum) % MOD;
        }
        return (int)ans;
    }
};

// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*d) where n is the number of jobs and d is the number of days
// SC: O(n*d) where n is the number of jobs and d is the number of days
// Approach: Dynamic Programming
// We can use a 2D dp array where dp[i][j] represents the minimum difficulty of scheduling the first i jobs in j days.
// The base case is dp[0][0] = 0, which means that if there are no jobs and no days, the minimum difficulty is 0.
// For each job, we can either schedule it on the current day or on a new day. If we schedule it on the current day, the difficulty of that day is the maximum difficulty of all jobs scheduled on that day. If we schedule it on a new day, the difficulty of that day is the difficulty of that job.
class Solution
{
    int dp[301][11];
    int func(vector<int> &jobDifficulty, int d, int i)
    {
        if (i == jobDifficulty.size())
        {
            return (d == 0) ? 0 : 1e9;
        }
        if (d == 0)
            return 1e9;
        if (dp[i][d] != -1)
            return dp[i][d];
        int ma = 0;
        int din = INT_MAX;
        for (int in = i; in < jobDifficulty.size(); in++)
        {
            ma = max(jobDifficulty[in], ma);
            int co = ma + func(jobDifficulty, d - 1, in + 1);
            din = min(din, co);
        }
        return dp[i][d] = din;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (d > n)
            return -1;
        memset(dp, -1, sizeof(dp));
        dp[n][0] = 0;
        for (int i = 1; i <= d; i++)
        {
            dp[n][i] = 1e9;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1e9;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int di = 1; di <= d; di++)
            {
                int ma = 0;
                int din = INT_MAX;
                for (int in = i; in < jobDifficulty.size(); in++)
                {
                    ma = max(jobDifficulty[in], ma);
                    int co = ma + dp[in + 1][di - 1];
                    din = min(din, co);
                }
                dp[i][di] = din;
            }
        }
        return dp[0][d];
    }
};

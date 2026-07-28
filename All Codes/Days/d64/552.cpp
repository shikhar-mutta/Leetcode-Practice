// Link: https://leetcode.com/problems/student-attendance-record-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: DP over state (absences so far: 0 or 1, trailing consecutive
// lates: 0,1,2). For each day, transition by appending 'P' (resets late
// streak), 'A' (only if absences==0, resets late streak, absences->1),
// or 'L' (only if late streak < 2, increments it). Sum all valid end
// states after n days, all mod 1e9+7.
class Solution
{
public:
    const long long mod = 1e9 + 7;
    int checkRecord(int n)
    {
        int dp[100001][2][3] = {0};
        fill(&dp[0][0][0], &dp[0][0][0] + 6, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    long long ans = dp[i - 1][j][0];
                    ans += (k < 2 ? dp[i - 1][j][k + 1] : 0);
                    ans += (j == 0 ? dp[i - 1][j + 1][0] : 0);
                    dp[i][j][k] = ans % mod;
                }
            }
        }

        return dp[n][0][0];
    }
};

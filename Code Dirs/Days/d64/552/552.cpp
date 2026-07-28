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
class Solution {
public:
    int checkRecord(int n) {
        const long long MOD = 1e9 + 7;
        // dp[a][l]: a = absences so far (0/1), l = trailing lates (0/1/2)
        long long dp[2][3] = {};
        dp[0][0] = 1;
        for (int day = 0; day < n; day++) {
            long long ndp[2][3] = {};
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    if (dp[a][l] == 0) continue;
                    long long cur = dp[a][l];
                    // append P
                    ndp[a][0] = (ndp[a][0] + cur) % MOD;
                    // append A
                    if (a == 0) ndp[1][0] = (ndp[1][0] + cur) % MOD;
                    // append L
                    if (l < 2) ndp[a][l + 1] = (ndp[a][l + 1] + cur) % MOD;
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        long long ans = 0;
        for (int a = 0; a < 2; a++)
            for (int l = 0; l < 3; l++)
                ans = (ans + dp[a][l]) % MOD;
        return (int)ans;
    }
};

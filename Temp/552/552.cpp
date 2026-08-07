// Link: https://leetcode.com/problems/student-attendance-record-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: DP over state (absences so far 0/1, trailing consecutive lates
// 0/1/2), transition by appending P, A, or L each day
class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        // dp[a][l]: a = absences (0/1), l = trailing lates (0/1/2)
        long long dp[2][3] = {{1,0,0},{0,0,0}};
        for (int day = 0; day < n; day++) {
            long long ndp[2][3] = {{0,0,0},{0,0,0}};
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    long long cur = dp[a][l];
                    if (cur == 0) continue;
                    // append P
                    ndp[a][0] = (ndp[a][0] + cur) % MOD;
                    // append A
                    if (a == 0) ndp[1][0] = (ndp[1][0] + cur) % MOD;
                    // append L
                    if (l < 2) ndp[a][l+1] = (ndp[a][l+1] + cur) % MOD;
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        long long total = 0;
        for (int a = 0; a < 2; a++)
            for (int l = 0; l < 3; l++)
                total = (total + dp[a][l]) % MOD;
        return (int)total;
    }
};

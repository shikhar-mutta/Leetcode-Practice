// Link: https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 5000)  SC: O(5000)
// Approach: each array element is bounded to [0,5000] (the range that makes
// the count finite). dp[v] = number of ways to build a valid non-decreasing
// prefix ending exactly at value v for the current position; transition to
// the next position via prefix sums of dp (any predecessor <= v extends
// non-decreasingly), keeping only values whose digit sum matches that
// position's target.
class Solution {
    static const long long MOD = 1000000007;
    static const int MAXV = 5000;
public:
    int countArrays(vector<int>& digitSum) {
        vector<int> ds(MAXV + 1);
        for (int v = 0; v <= MAXV; v++) {
            int x = v, s = 0;
            while (x) { s += x % 10; x /= 10; }
            ds[v] = s;
        }

        int n = digitSum.size();
        vector<long long> dp(MAXV + 1, 0);
        for (int v = 0; v <= MAXV; v++) if (ds[v] == digitSum[0]) dp[v] = 1;

        for (int i = 1; i < n; i++) {
            vector<long long> pre(MAXV + 1);
            pre[0] = dp[0];
            for (int v = 1; v <= MAXV; v++) pre[v] = (pre[v-1] + dp[v]) % MOD;

            vector<long long> ndp(MAXV + 1, 0);
            for (int v = 0; v <= MAXV; v++) if (ds[v] == digitSum[i]) ndp[v] = pre[v];
            dp = move(ndp);
        }

        long long ans = 0;
        for (int v = 0; v <= MAXV; v++) ans = (ans + dp[v]) % MOD;
        return (int)ans;
    }
};

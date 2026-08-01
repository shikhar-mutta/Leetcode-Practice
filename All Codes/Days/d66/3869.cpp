// Link: https://leetcode.com/problems/count-fancy-numbers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(digits * digitSum * 10 * 4)  SC: O(digits * digitSum * 10 * 4)
// Approach: a "good" number has strictly monotonic (increasing or
// decreasing) digits; a "fancy" number is good itself, or its digit sum is
// good. answer = f(r) - f(l-1) via digit DP tracking (position, running
// digit sum, previous digit, monotonic state: 0=undetermined,
// 1=increasing, 2=decreasing, 3=broken). At a leaf, count if state!=3
// (itself good), else check whether the digit sum is good (digit sums fit
// in <=3 digits given n<=16, so checked directly by digit pattern).
class Solution {
    string num;
    int n;
    vector<vector<vector<vector<long long>>>> memo;

    bool check(int s) {
        if (s < 100) return s % 11 != 0;
        int mid = (s / 10) % 10;
        int last = s % 10;
        return mid > 1 && mid < last;
    }

    long long dfs(int pos, int s, int prev, int st, bool lim) {
        if (pos >= n) {
            if (st != 3) return 1;
            return check(s) ? 1 : 0;
        }
        if (!lim && memo[pos][s][prev][st] != -1) return memo[pos][s][prev][st];
        int up = lim ? (num[pos] - '0') : 9;
        long long res = 0;
        for (int i = 0; i <= up; i++) {
            int nxtSt;
            if (st == 0) {
                if (prev == 0) nxtSt = 0;
                else if (i > prev) nxtSt = 1;
                else if (i < prev) nxtSt = 2;
                else nxtSt = 3;
            } else if (st == 1) {
                nxtSt = (i > prev) ? 1 : 3;
            } else if (st == 2) {
                nxtSt = (i < prev) ? 2 : 3;
            } else {
                nxtSt = 3;
            }
            res += dfs(pos + 1, s + i, i, nxtSt, lim && i == up);
        }
        if (!lim) memo[pos][s][prev][st] = res;
        return res;
    }

    long long f(long long x) {
        if (x < 0) return 0;
        num = to_string(x);
        n = num.size();
        memo.assign(n, vector<vector<vector<long long>>>(9*n+1, vector<vector<long long>>(10, vector<long long>(4, -1))));
        return dfs(0, 0, 0, 0, true);
    }
public:
    long long countFancy(long long l, long long r) {
        return f(r) - f(l - 1);
    }
};

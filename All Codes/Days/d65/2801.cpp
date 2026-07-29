// Link: https://leetcode.com/problems/count-stepping-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len * 10), SC: O(len * 10)
// Approach: answer = f(high) - f(low - 1), where f(X) counts stepping numbers (adjacent digits
// differ by exactly 1) in [0, X] via digit DP memoized on (position, last digit) for the
// non-tight, already-started branch. Big-number decrement handles low - 1.
class Solution {
public:
    const long long MOD = 1e9+7;
    string num;
    vector<vector<long long>> memo; // memo[pos][last+1], last in [-1,9]

    long long dp(int pos, int last, bool tight, bool started) {
        if (pos == (int)num.size()) return started ? 1 : 0;
        if (!tight && started && memo[pos][last+1] != -1) return memo[pos][last+1];

        int limit = tight ? (num[pos] - '0') : 9;
        long long total = 0;
        for (int d = 0; d <= limit; d++) {
            if (!started && d == 0) {
                total = (total + dp(pos+1, -1, tight && d == limit, false)) % MOD;
            } else {
                if (started && abs(d - last) != 1) continue;
                total = (total + dp(pos+1, d, tight && d == limit, true)) % MOD;
            }
        }
        if (!tight && started) memo[pos][last+1] = total;
        return total;
    }

    long long f(const string& X) {
        num = X;
        memo.assign(num.size(), vector<long long>(11, -1));
        return dp(0, -1, true, false);
    }

    string decrement(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') { s[i] = '9'; i--; }
        if (i < 0) return "";
        s[i]--;
        int start = 0;
        while (start < (int)s.size() - 1 && s[start] == '0') start++;
        return s.substr(start);
    }

    int countSteppingNumbers(string low, string high) {
        long long hi = f(high);
        string lowMinus1 = decrement(low);
        long long lo = lowMinus1.empty() ? 0 : f(lowMinus1);
        return (int)(((hi - lo) % MOD + MOD) % MOD);
    }
};

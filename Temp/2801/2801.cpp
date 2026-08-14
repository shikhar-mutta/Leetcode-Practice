// Link: https://leetcode.com/problems/count-stepping-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long MOD = 1e9 + 7;

    long long countUpTo(string &num) {
        if (num == "-1") return 0;
        int n = num.size();
        // memo[pos][lastDigit] valid only when !tight
        vector<vector<long long>> memo(n, vector<long long>(10, -1));

        function<long long(int,int,bool,bool)> dfs = [&](int pos, int last, bool tight, bool started) -> long long {
            if (pos == n) return started ? 1 : 0;
            if (!tight && started && memo[pos][last] != -1) return memo[pos][last];

            int limit = tight ? (num[pos] - '0') : 9;
            long long total = 0;
            for (int d = 0; d <= limit; d++) {
                if (!started && d == 0) {
                    total = (total + dfs(pos+1, 0, tight && (d==limit), false)) % MOD;
                } else if (!started || abs(d - last) == 1) {
                    total = (total + dfs(pos+1, d, tight && (d==limit), true)) % MOD;
                }
            }
            if (!tight && started) memo[pos][last] = total;
            return total;
        };

        return dfs(0, 0, true, false);
    }

    string subtractOne(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0 && num[i] == '0') { num[i] = '9'; i--; }
        if (i < 0) return "-1";
        num[i]--;
        int start = 0;
        while (start < n - 1 && num[start] == '0') start++;
        string res = num.substr(start);
        if (res == "0" && n > 1) {
            // check if original was "0" only (shouldn't happen given num1 handling elsewhere)
        }
        return res;
    }

public:
    int countSteppingNumbers(string low, string high) {
        long long upper = countUpTo(high);
        string lowMinus1 = (low == "0") ? "-1" : subtractOne(low);
        long long lower = countUpTo(lowMinus1);
        long long ans = ((upper - lower) % MOD + MOD) % MOD;
        if (low == "0") ans = (ans + 1) % MOD; // account for 0 itself, missed by the positive-number DP
        return (int)ans;
    }
};

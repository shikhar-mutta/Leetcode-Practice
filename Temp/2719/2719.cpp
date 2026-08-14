// Link: https://leetcode.com/problems/count-of-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long MOD = 1e9 + 7;

    long long countUpTo(string &num, int min_sum, int max_sum) {
        int n = num.size();
        vector<vector<long long>> memo(n, vector<long long>(min_sum + max_sum + 1, -1));

        function<long long(int,int,bool)> dfs = [&](int pos, int sumSoFar, bool tight) -> long long {
            if (sumSoFar > max_sum) return 0;
            if (pos == n) return (sumSoFar >= min_sum) ? 1 : 0;
            if (!tight && memo[pos][sumSoFar] != -1) return memo[pos][sumSoFar];

            int limit = tight ? (num[pos] - '0') : 9;
            long long total = 0;
            for (int d = 0; d <= limit; d++) {
                total = (total + dfs(pos + 1, sumSoFar + d, tight && (d == limit))) % MOD;
            }
            if (!tight) memo[pos][sumSoFar] = total;
            return total;
        };

        return dfs(0, 0, true);
    }

    string subtractOne(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0 && num[i] == '0') { num[i] = '9'; i--; }
        num[i]--;
        int start = 0;
        while (start < n - 1 && num[start] == '0') start++;
        return num.substr(start);
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        long long upper = countUpTo(num2, min_sum, max_sum);
        long long lower = 0;
        if (num1 != "0") {
            string num1minus1 = subtractOne(num1);
            lower = countUpTo(num1minus1, min_sum, max_sum);
        }
        long long ans = ((upper - lower) % MOD + MOD) % MOD;
        return (int)ans;
    }
};

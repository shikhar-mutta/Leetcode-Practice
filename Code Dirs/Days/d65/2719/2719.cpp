// Link: https://leetcode.com/problems/count-of-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len * maxSum), SC: O(len * maxSum)
// Approach: answer = f(num2) - f(num1 - 1) where f(X) counts integers in [0, X] whose digit sum
// lies in [min_sum, max_sum], computed via digit DP (memoized on position + running sum for the
// non-tight branch).
class Solution {
public:
    const long long MOD = 1e9+7;
    int minSum, maxSum;
    string num;
    vector<vector<long long>> memo;

    long long dp(int pos, int sum, bool tight) {
        if (sum > maxSum) return 0;
        if (pos == (int)num.size()) return (sum >= minSum) ? 1 : 0;
        if (!tight && memo[pos][sum] != -1) return memo[pos][sum];

        int limit = tight ? (num[pos] - '0') : 9;
        long long ways = 0;
        for (int d = 0; d <= limit; d++) {
            ways = (ways + dp(pos + 1, sum + d, tight && d == limit)) % MOD;
        }
        if (!tight) memo[pos][sum] = ways;
        return ways;
    }

    long long f(string X) {
        num = X;
        memo.assign(num.size(), vector<long long>(maxSum + 1, -1));
        return dp(0, 0, true);
    }

    string decrement(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') { s[i] = '9'; i--; }
        if (i < 0) return ""; // s was all zeros -> below 0
        s[i]--;
        int start = 0;
        while (start < (int)s.size() - 1 && s[start] == '0') start++;
        return s.substr(start);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        minSum = min_sum; maxSum = max_sum;
        long long high = f(num2);
        string num1Minus1 = decrement(num1);
        long long low = num1Minus1.empty() ? 0 : f(num1Minus1);
        return (int)(((high - low) % MOD + MOD) % MOD);
    }
};

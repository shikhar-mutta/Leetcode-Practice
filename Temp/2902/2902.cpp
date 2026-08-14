// Link: https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const long long MOD = 1e9 + 7;
        map<int, int> freq;
        for (int x : nums) freq[x]++;
        long long zeroCount = 0;
        if (freq.count(0)) { zeroCount = freq[0]; freq.erase(0); }

        long long totalSum = 0;
        for (int x : nums) totalSum += x;
        int maxSum = min((long long)r, totalSum);
        if (maxSum < 0) return 0;

        vector<long long> dp(maxSum + 1, 0);
        dp[0] = 1;
        for (auto& [v, c] : freq) {
            vector<long long> ndp(maxSum + 1);
            long long limit = (long long)v * (c + 1);
            for (int s = 0; s <= maxSum; s++) {
                ndp[s] = dp[s];
                if (s >= v) ndp[s] = (ndp[s] + ndp[s - v]) % MOD;
                if (s >= limit) ndp[s] = (ndp[s] - dp[s - limit] + MOD) % MOD;
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int s = l; s <= maxSum; s++) ans = (ans + dp[s]) % MOD;
        ans = ans * ((zeroCount + 1) % MOD) % MOD;
        return (int)ans;
    }
};

// Link: https://leetcode.com/problems/sum-of-good-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const long long MOD = 1000000007;
        int maxVal = 100001;
        vector<long long> cnt(maxVal + 2, 0), sum(maxVal + 2, 0);

        long long ans = 0;
        for (int v : nums) {
            long long prevCnt = 0, prevSum = 0;
            if (v - 1 >= 0) { prevCnt = (prevCnt + cnt[v-1]) % MOD; prevSum = (prevSum + sum[v-1]) % MOD; }
            prevCnt = (prevCnt + cnt[v+1]) % MOD;
            prevSum = (prevSum + sum[v+1]) % MOD;

            long long newCount = (1 + prevCnt) % MOD;
            long long newSum = ((long long)v * newCount % MOD + prevSum) % MOD;

            cnt[v] = (cnt[v] + newCount) % MOD;
            sum[v] = (sum[v] + newSum) % MOD;

            ans = (ans + newSum) % MOD;
        }
        return (int)ans;
    }
};

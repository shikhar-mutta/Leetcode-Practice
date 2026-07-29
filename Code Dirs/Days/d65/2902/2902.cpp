// Link: https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(distinctVals * r), SC: O(r)
// Approach: bounded-knapsack sum-counting. Group by value with its multiplicity. For each
// distinct nonzero value v with count c, update dp[s] (number of ways to reach sum s) using a
// sliding-window prefix sum over residue classes mod v (bounded by c+1 terms), which processes
// each value in O(r) instead of O(r*c). Zeros never change the sum, so they just multiply the
// final count by (countOfZeros + 1).
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const long long MOD = 1e9+7;
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int zeroCount = freq.count(0) ? freq[0] : 0;
        vector<int> vals;
        for (auto& [v, c] : freq) if (v != 0) vals.push_back(v);

        vector<long long> dp(r+1, 0);
        dp[0] = 1;
        for (int v : vals) {
            int c = freq[v];
            vector<long long> ndp(r+1, 0);
            for (int rem = 0; rem < v && rem <= r; rem++) {
                long long prefix = 0;
                for (int s = rem; s <= r; s += v) {
                    prefix = (prefix + dp[s]) % MOD;
                    int drop = s - (long long)(c+1) * v;
                    if (drop >= 0) prefix = (prefix - dp[drop] + MOD) % MOD;
                    ndp[s] = prefix;
                }
            }
            dp = ndp;
        }

        long long sum = 0;
        for (int s = l; s <= r; s++) sum = (sum + dp[s]) % MOD;
        sum = sum * (zeroCount + 1) % MOD;
        return (int)sum;
    }
};

// Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bitCount(30, 0);
        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if (x & (1 << b)) bitCount[b]++;

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 0; b < 30; b++) {
                if (bitCount[b] > 0) {
                    bitCount[b]--;
                    val |= (1LL << b);
                }
            }
            ans = (ans + val % MOD * (val % MOD)) % MOD;
        }
        return (int)ans;
    }
};

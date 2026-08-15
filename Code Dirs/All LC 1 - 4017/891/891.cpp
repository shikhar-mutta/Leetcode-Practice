// Link: https://leetcode.com/problems/sum-of-subsequence-widths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) pow2[i] = pow2[i-1] * 2 % MOD;

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long term = (pow2[i] - pow2[n-1-i] + MOD) % MOD;
            res = (res + (long long)nums[i] % MOD * term) % MOD;
        }
        return (int)res;
    }
};

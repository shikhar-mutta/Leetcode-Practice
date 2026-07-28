// Link: https://leetcode.com/problems/sum-of-subsequence-widths/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(1)
// Approach: sort nums. Each element at sorted index i acts as the max
// of 2^i subsequences (choosing any subset of the i smaller elements to
// include with it) and as the min of 2^(n-1-i) subsequences, so its net
// contribution to the total width sum is nums[i] * (2^i - 2^(n-1-i)).
// Precompute powers of 2 mod 1e9+7 and sum contributions.
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long coeff = (pow2[i] - pow2[n - 1 - i] + MOD) % MOD;
            ans = (ans + (long long)nums[i] % MOD * coeff) % MOD;
        }
        return (int)ans;
    }
};

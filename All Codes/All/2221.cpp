// Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) per call after a one-time O(1000^2) amortized Pascal's-triangle
//     precompute (shared across instances via the static flag)
// SC: O(1000^2) for the static ncr table
// Approach: repeatedly summing adjacent pairs mod 10 is equivalent to a
// single pass computing sum_i C(n-1, i) * nums[i] mod 10 (Pascal's triangle
// coefficients, same reasoning as expanding (x+y)^k), so precompute
// binomial coefficients mod 10 once (static, built lazily on first
// construction) and evaluate that weighted sum directly instead of
// simulating each triangular reduction step.
class Solution {
public:
    static inline long long ncr[1001][1001];
    static inline bool flag = false;
    static inline int mod = 10;
    Solution() {
        if (flag == true)
            return;
        ncr[0][0] = 1;
        ncr[1][0] = 1;
        ncr[1][1] = 1;
        for (int i = 2; i < 1001; i++) {
            ncr[i][0] = 1;
            for (int j = 1; j < i; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
            }
            ncr[i][i] = 1;
        }
        flag = true;
        return;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int coef = ncr[n - 1][i];
            sum = (sum + 1ll * coef * nums[i]) % 10;
        }
        return sum;
    }
};

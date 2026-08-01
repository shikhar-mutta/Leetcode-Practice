// Link: https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(n*k)
// Approach: strength = sum over the j-th chosen subarray (1-indexed) of
// coeff(j) * sum(subarray), where coeff(j) = (k-j+1) * (+1 if j odd, -1
// if j even). DP over (position, subarrays completed, in/out of current
// subarray): dpIn[i][j] = best strength ending at i while inside the j-th
// subarray; dpNotIn[i][j] = best strength at i having finished exactly j
// subarrays (or not started the next). Each element either extends the
// current subarray, starts a new one, or is skipped.
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;
        vector<vector<long long>> dpIn(n + 1, vector<long long>(k + 1, NEG));
        vector<vector<long long>> dpNotIn(n + 1, vector<long long>(k + 1, NEG));
        dpNotIn[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dpNotIn[i][0] = 0;
            for (int j = 1; j <= k; j++) {
                long long coeff = (long long)(k - j + 1) * (j % 2 == 1 ? 1 : -1);
                long long startOrExtend = max(dpIn[i-1][j], dpNotIn[i-1][j-1]);
                dpIn[i][j] = (startOrExtend > NEG) ? coeff * nums[i-1] + startOrExtend : NEG;
                dpNotIn[i][j] = max(dpNotIn[i-1][j], dpIn[i][j]);
            }
        }
        return max(dpNotIn[n][k], dpIn[n][k]);
    }
};

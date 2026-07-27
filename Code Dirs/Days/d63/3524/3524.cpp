// Link: https://leetcode.com/problems/find-x-value-of-array-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k) SC: O(k)
// Approach: removing a prefix/suffix leaves a contiguous subarray, so we
// need counts of (product mod k) over ALL non-empty subarrays. For each
// ending index j, dpCur[r] = number of subarrays ending at j with product
// mod k == r, built from dpPrev (subarrays ending at j-1) by extending
// each with nums[j], plus the length-1 subarray [nums[j]] itself. Sum
// dpCur into the running answer at each step.
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dpPrev(k, 0);
        for (int num : nums) {
            vector<long long> dpCur(k, 0);
            int r = num % k;
            for (int x = 0; x < k; x++) {
                if (dpPrev[x] > 0) dpCur[(x * num) % k] += dpPrev[x];
            }
            dpCur[r] += 1;
            for (int x = 0; x < k; x++) ans[x] += dpCur[x];
            dpPrev = dpCur;
        }
        return ans;
    }
};

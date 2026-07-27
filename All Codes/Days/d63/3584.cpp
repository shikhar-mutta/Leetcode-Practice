// Link: https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: a length-m subsequence's first/last elements are nums[i] and
// nums[j] for some i, j with j-i >= m-1. For each i, the best j is
// whichever of the suffix max or suffix min (starting at i+m-1) gives
// the larger product with nums[i] (covers both positive*positive and
// negative*negative maximizing cases).
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> sufMax(n), sufMin(n);
        sufMax[n-1] = sufMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max((long long)nums[i], sufMax[i+1]);
            sufMin[i] = min((long long)nums[i], sufMin[i+1]);
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i + m - 1 < n; i++) {
            int j = i + m - 1;
            ans = max(ans, nums[i] * sufMax[j]);
            ans = max(ans, nums[i] * sufMin[j]);
        }
        return ans;
    }
};

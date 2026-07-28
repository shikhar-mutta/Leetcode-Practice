// Link: https://leetcode.com/problems/longest-non-decreasing-subarray-after-replacing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: precompute left[i] = length of non-decreasing run ending at
// i, right[i] = length starting at i. For each index i considered as the
// replaced element, it can bridge left[i-1] and right[i+1] whenever
// nums[i-1] <= nums[i+1] (any value in between works); otherwise it can
// only extend the longer of the two sides by one.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) left[i] = (nums[i] >= nums[i-1]) ? left[i-1] + 1 : 1;
        for (int i = n - 2; i >= 0; i--) right[i] = (nums[i] <= nums[i+1]) ? right[i+1] + 1 : 1;

        int ans = *max_element(left.begin(), left.end());
        for (int i = 0; i < n; i++) {
            int l = (i > 0) ? left[i-1] : 0;
            int r = (i < n-1) ? right[i+1] : 0;
            int cand;
            if (i > 0 && i < n-1 && nums[i-1] <= nums[i+1]) cand = l + 1 + r;
            else cand = max(l, r) + 1;
            ans = max(ans, cand);
        }
        return ans;
    }
};

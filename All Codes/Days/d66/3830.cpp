// Link: https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: precompute l1[i]/l2[i] = longest alternating run ending at i
// whose last step was an increase/decrease, and r1[i]/r2[i] = longest run
// starting at i whose first step (going right) is an increase/decrease.
// The no-deletion answer is the max l1/l2 value. For each candidate deleted
// index i (1..n-2), nums[i-1] and nums[i+1] become adjacent; if that new
// step is an increase, the merged run is l2[i-1]+r2[i+1] (must have ended
// in a decrease before, to alternate into an increase), symmetric for a
// decrease.
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int> l1(n, 1), l2(n, 1), r1(n, 1), r2(n, 1);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) l1[i] = l2[i-1] + 1;
            else if (nums[i-1] > nums[i]) l2[i] = l1[i-1] + 1;
            ans = max({ans, l1[i], l2[i]});
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i+1] > nums[i]) r1[i] = r2[i+1] + 1;
            else if (nums[i+1] < nums[i]) r2[i] = r1[i+1] + 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i-1] < nums[i+1]) ans = max(ans, l2[i-1] + r2[i+1]);
            else if (nums[i-1] > nums[i+1]) ans = max(ans, l1[i-1] + r1[i+1]);
        }
        return ans;
    }
};

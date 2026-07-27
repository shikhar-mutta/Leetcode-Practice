// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: run[i] = length of strictly increasing run ending at i,
// fwd[i] = length of strictly increasing run starting at i. For every
// split point i (left subarray ends at i, right starts at i+1), the best
// equal-length k achievable there is min(run[i], fwd[i+1]); answer is the
// max over all splits (this also naturally covers splitting one long run
// in half).
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> run(n), fwd(n);
        run[0] = 1;
        for (int i = 1; i < n; i++) run[i] = (nums[i] > nums[i-1]) ? run[i-1] + 1 : 1;
        fwd[n-1] = 1;
        for (int i = n-2; i >= 0; i--) fwd[i] = (nums[i] < nums[i+1]) ? fwd[i+1] + 1 : 1;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) ans = max(ans, min(run[i], fwd[i+1]));
        return ans;
    }
};

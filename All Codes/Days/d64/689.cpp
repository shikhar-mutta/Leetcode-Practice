// Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: compute window sums, then left[i] = start index of the best
// window in [0,i] (ties favor earlier index), right[i] = best window
// start in [i,n-1] (ties favor earlier index). For each middle window
// start m, combine best left window ending before it and best right
// window starting after it, tracking the overall max total.
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int numWindows = n - k + 1;
        vector<int> winSum(numWindows);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) winSum[i - k + 1] = sum;
        }

        vector<int> left(numWindows);
        int best = 0;
        for (int i = 0; i < numWindows; i++) {
            if (winSum[i] > winSum[best]) best = i;
            left[i] = best;
        }

        vector<int> right(numWindows);
        best = numWindows - 1;
        for (int i = numWindows - 1; i >= 0; i--) {
            if (winSum[i] >= winSum[best]) best = i;
            right[i] = best;
        }

        int bestTotal = -1;
        vector<int> ans(3);
        for (int m = k; m <= numWindows - 1 - k; m++) {
            int l = left[m - k];
            int r = right[m + k];
            int total = winSum[l] + winSum[m] + winSum[r];
            if (total > bestTotal) {
                bestTotal = total;
                ans = {l, m, r};
            }
        }
        return ans;
    }
};

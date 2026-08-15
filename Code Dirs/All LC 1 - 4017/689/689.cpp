// Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: compute window sums; left[i] = index of best window start in [0,i] (leftmost on tie), right[i] = index of best window start in [i,n-1] (leftmost on tie). Then try every middle window position and combine with best left/right choices.
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int numWindows = n - k + 1;
        vector<int> winSum(numWindows);
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        winSum[0] = sum;
        for (int i = 1; i < numWindows; i++) {
            sum += nums[i+k-1] - nums[i-1];
            winSum[i] = sum;
        }
        vector<int> left(numWindows), right(numWindows);
        int best = 0;
        for (int i = 0; i < numWindows; i++) {
            if (winSum[i] > winSum[best]) best = i;
            left[i] = best;
        }
        best = numWindows-1;
        for (int i = numWindows-1; i >= 0; i--) {
            if (winSum[i] >= winSum[best]) best = i;
            right[i] = best;
        }
        vector<int> ans = {-1,-1,-1};
        int bestTotal = -1;
        for (int mid = k; mid <= numWindows-1-k; mid++) {
            int l = left[mid-k], r = right[mid+k];
            int total = winSum[l] + winSum[mid] + winSum[r];
            if (total > bestTotal) {
                bestTotal = total;
                ans = {l, mid, r};
            }
        }
        return ans;
    }
};

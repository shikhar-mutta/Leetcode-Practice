// Link: https://leetcode.com/problems/maximum-score-of-spliced-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: swapping a subarray [l,r] between nums1,nums2 changes sum1 by sum(nums2-nums1) over that range.
// Kadane's on diff arrays both directions, add to base sums, take overall max.
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) { sum1 += nums1[i]; sum2 += nums2[i]; }

        auto maxKadane = [&](vector<int>& a, vector<int>& b) {
            long long best = 0, cur = 0;
            for (int i = 0; i < n; i++) {
                cur += (b[i] - a[i]);
                if (cur < 0) cur = 0;
                best = max(best, cur);
            }
            return best;
        };

        long long ans1 = sum1 + maxKadane(nums1, nums2);
        long long ans2 = sum2 + maxKadane(nums2, nums1);
        return (int)max(ans1, ans2);
    }
};

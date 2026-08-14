// Link: https://leetcode.com/problems/maximum-score-of-spliced-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long sum1 = 0, sum2 = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff[i] = nums1[i] - nums2[i];
        }

        long long maxKadane = diff[0], curMax = diff[0];
        long long minKadane = diff[0], curMin = diff[0];
        for (int i = 1; i < n; i++) {
            curMax = max((long long)diff[i], curMax + diff[i]);
            maxKadane = max(maxKadane, curMax);
            curMin = min((long long)diff[i], curMin + diff[i]);
            minKadane = min(minKadane, curMin);
        }

        long long best1 = sum1 - min(0LL, minKadane); // maximize nums1 by swapping in the most-negative diff segment
        long long best2 = sum2 + max(0LL, maxKadane); // maximize nums2 by swapping in the most-positive diff segment
        return (int)max(best1, best2);
    }
};

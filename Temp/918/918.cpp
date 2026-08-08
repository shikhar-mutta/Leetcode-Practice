// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, curMax = 0, maxSum = INT_MIN, curMin = 0, minSum = INT_MAX;
        for (int x : nums) {
            total += x;
            curMax = max(curMax + x, x);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + x, x);
            minSum = min(minSum, curMin);
        }
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};

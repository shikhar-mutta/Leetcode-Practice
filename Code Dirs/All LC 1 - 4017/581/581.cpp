// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track max seen from left and min seen from right; the last index where nums[i] < maxSoFar and first index where nums[i] > minSoFar define the boundary of the unsorted subarray.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN, right = -1;
        int minSoFar = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (nums[i] < maxSoFar) right = i;
        }
        for (int i = n-1; i >= 0; i--) {
            minSoFar = min(minSoFar, nums[i]);
            if (nums[i] > minSoFar) left = i;
        }
        if (right == -1) return 0;
        return right - left + 1;
    }
};

// Link: https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        long long cost = 0;
        if (nums[mid] > k) {
            for (int i = mid; i >= 0 && nums[i] > k; i--) cost += nums[i] - k;
        } else if (nums[mid] < k) {
            for (int i = mid; i < n && nums[i] < k; i++) cost += k - nums[i];
        }
        return cost;
    }
};

// Link: https://leetcode.com/problems/smallest-range-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[n-1] - nums[0];
        for (int i = 0; i + 1 < n; i++) {
            int hi = max(nums[n-1] - k, nums[i] + k);
            int lo = min(nums[0] + k, nums[i+1] - k);
            res = min(res, hi - lo);
        }
        return res;
    }
};

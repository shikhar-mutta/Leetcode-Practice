// Link: https://leetcode.com/problems/maximum-total-subarray-value-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: a subarray's value (max-min) can never exceed the whole
// array's global max-min, and choosing the entire array achieves that
// bound. Since subarrays can be reused across the k picks, the optimum
// is just picking the full array every time: k * (globalMax - globalMin).
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return (long long)k * (mx - mn);
    }
};

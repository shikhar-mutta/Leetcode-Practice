// Link: https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: sliding window; shrink from left while product >= k, then add (right-left+1) subarrays ending at right.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        long long prod = 1;
        int left = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};

// Link: https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track running max and min product ending at each index (min matters since a negative
// can flip it to the new max), swap them when the current number is negative
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (x < 0) swap(curMax, curMin);
            curMax = max(x, curMax * x);
            curMin = min(x, curMin * x);
            best = max(best, curMax);
        }
        return best;
    }
};

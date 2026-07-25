// Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: precompute the total sum, then sweep left to right maintaining
// a running left-side sum; the right-side sum is just total-left. Count
// every split index (excluding the last, since the right side must stay
// non-empty) where the left sum is >= the right sum.
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums)
            total += x;

        long long left = 0;
        int count = 0;
        for (int i = 0; i < n - 1;
             ++i) { // split must leave a non-empty right side
            left += nums[i];
            long long right = total - left;
            if (left >= right)
                ++count;
        }
        return count;
    }
};

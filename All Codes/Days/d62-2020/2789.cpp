// Link: https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: merges always combine an element into the accumulated sum to its
// right (never leftward first), so process right to left greedily: if the
// current element is <= the accumulated sum so far, merge it in (always
// beneficial since it only grows the rightmost block); otherwise it starts a
// new block. No explicit running max is needed: a reset only happens when the
// new block already starts bigger than the block it replaces, and merges only
// grow it further, so the final block (the one containing index 0) is
// guaranteed to be >= every earlier block — it IS the answer.
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= sum)
                sum += nums[i]; // merge: nums[i] <= accumulated right side
            else
                sum = nums[i]; // can't merge: reset
        }
        return sum;
    }
};

// Link: https://leetcode.com/problems/make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: process right to left with a stack that stays non-decreasing
// from top to bottom (i.e. non-decreasing left-to-right once reversed).
// A new element x (further left) that's bigger than the current top can't
// coexist with it in a non-decreasing array, so it must absorb (merge
// into, via the "replace subarray with its max" operation) that smaller
// kept element — pop while top < x, then push x. Final stack size is the
// max achievable length.
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> stk;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            while (!stk.empty() && stk.back() < x) stk.pop_back();
            stk.push_back(x);
        }
        return stk.size();
    }
};

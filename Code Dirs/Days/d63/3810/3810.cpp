// Link: https://leetcode.com/problems/minimum-operations-to-reach-target-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: a position can only ever be touched by an operation whose
// chosen value x equals its ORIGINAL nums value (since until touched it
// keeps that value, and any op targeting a different value can't select
// it). So every distinct original value appearing at a mismatched
// position needs exactly one dedicated operation, and one operation
// suffices to fix every (possibly scattered) occurrence of that value
// at once. The answer is simply the count of distinct nums[i] values
// among positions where nums[i] != target[i].
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> vals;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != target[i]) vals.insert(nums[i]);
        }
        return vals.size();
    }
};

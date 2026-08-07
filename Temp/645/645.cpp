// Link: https://leetcode.com/problems/set-mismatch/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: use index sign-marking; for each value, negate nums[val-1] if positive; if already negative, val is the duplicate. Missing number is the index whose value stays positive.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] < 0) dup = abs(x);
            else nums[idx] = -nums[idx];
        }
        int missing = -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) missing = i+1;
        return {dup, missing};
    }
};

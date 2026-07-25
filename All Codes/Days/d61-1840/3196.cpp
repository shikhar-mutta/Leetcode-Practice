// Link: https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: DP with two running states per index i - pos (best cost of an
// alternating run ending at i with nums[i] taken as +) and neg (ending at i
// with nums[i] taken as -). newPos either starts a fresh subarray at i or
// extends a run that just took a - at i-1; newNeg only extends the previous
// run by flipping sign. Answer is max(pos, neg) after the pass.
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        // pos: nums[i] taken positive; neg: nums[i] taken negative
        long long pos = nums[0],
                  neg = nums[0]; // at i=0 both start a subarray (positive)
        for (int i = 1; i < n; ++i) {
            long long newPos =
                max(pos, neg) +
                nums[i]; // start new subarray OR after a negative
            long long newNeg =
                pos - nums[i]; // continue subarray with alternating sign
            pos = newPos;
            neg = newNeg;
        }
        return max(pos, neg);
    }
};

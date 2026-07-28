// Link: https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: the minimum total x needed to raise a "required increase"
// profile built from stacked range-additions equals the sum of its
// positive jumps. The minimal required increase at each index is just
// enough to not dip below the previous (already-fixed) element, so the
// answer reduces to summing max(0, nums[i-1]-nums[i]) across adjacent
// pairs.
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            ans += max(0, nums[i-1] - nums[i]);
        }
        return ans;
    }
};

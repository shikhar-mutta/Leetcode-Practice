// Link: https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the minimum achievable AND-sum total is the AND of the whole
// array; if that's nonzero, the array can't be split (score of any single
// piece is >= that value, so 1 subarray is optimal, giving score 0 only if
// undivided, else worse) - special-cased as returning 1. Otherwise greedily
// extend a running AND (starting all-ones) and cut a new subarray the
// moment it hits 0, maximizing the subarray count while keeping every
// piece's AND at the minimum possible value (0).
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int all = nums[0];
        for (int i = 1; i < nums.size(); i++)
            all &= nums[i];

        if (all != 0)
            return 1;

        int ans = 0;
        int cur = -1; // all bits set-> key point

        for (int x : nums) {
            cur &= x;
            if (cur == 0) {
                ans++;
                cur = -1;
            }
        }

        return ans;
    }
};

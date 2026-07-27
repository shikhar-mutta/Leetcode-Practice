// Link: https://leetcode.com/problems/minimum-increase-to-maximize-special-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: only increases are allowed and neighbors are never touched,
// so making index i a peak costs max(0, max(nums[i-1],nums[i+1])+1-nums[i]),
// independent of any other selected peak (selected peaks must be
// non-adjacent, like house-robber). The maximum achievable peak count is
// fixed combinatorially by n; among all selections achieving that max
// count, DP (comparing by count desc, then cost asc) finds the min cost.
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        using P = pair<int, long long>; // (count, cost)
        auto better = [](const P& a, const P& b) {
            if (a.first != b.first) return a.first > b.first ? a : b;
            return a.second < b.second ? a : b;
        };

        P prev2 = {0, 0}, prev1 = {0, 0}; // dp before first candidate
        for (int i = 1; i <= n - 2; i++) {
            long long cost = max(0LL, (long long)max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            P take = {prev2.first + 1, prev2.second + cost};
            P cur = better(prev1, take);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1.second;
    }
};

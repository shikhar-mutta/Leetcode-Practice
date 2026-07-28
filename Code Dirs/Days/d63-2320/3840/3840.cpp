// Link: https://leetcode.com/problems/house-robber-v/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: DP tracking two states per index: best total not picking
// house i (max of both previous states) vs picking house i (nums[i] plus
// the previous "not picked" state, and also the previous "picked" state
// if adjacent colors differ, since then both can coexist).
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        long long dp0 = 0, dp1 = nums[0];
        for (int i = 1; i < n; i++) {
            long long ndp1 = nums[i] + dp0;
            if (colors[i] != colors[i-1]) ndp1 = max(ndp1, nums[i] + dp1);
            long long ndp0 = max(dp0, dp1);
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return max(dp0, dp1);
    }
};

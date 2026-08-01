// Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: since the tree is connected, any pair of nodes can be
// XOR-flipped via edges along their path (each edge use is optional), so
// overall any EVEN number of nodes can be freely chosen to flip. Compute
// gain[i] = (nums[i]^k) - nums[i]; take the base sum plus all positive
// gains; if an odd number of gains were taken, drop the smallest positive
// gain or include the least-negative gain, whichever costs less.
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long base = 0;
        vector<int> gains;
        for (int x : nums) {
            base += x;
            gains.push_back((x ^ k) - x);
        }
        sort(gains.begin(), gains.end(), greater<int>());
        long long total = base;
        int flips = 0;
        for (int g : gains) {
            if (g > 0) { total += g; flips++; }
        }
        if (flips % 2 == 1) {
            long long bestAdjust = LLONG_MIN;
            if (flips >= 1) bestAdjust = max(bestAdjust, (long long)(-gains[flips - 1])); // undo smallest taken gain
            if (flips < n) bestAdjust = max(bestAdjust, (long long)gains[flips]); // include next (negative) gain
            total += bestAdjust;
        }
        return total;
    }
};

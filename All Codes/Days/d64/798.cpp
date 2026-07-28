// Link: https://leetcode.com/problems/smallest-rotation-with-highest-score/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: for rotation k, element at index i moves to (i-k+n)%n and
// scores a point iff nums[i] <= new position j. As k varies, j=(i-k)%n
// sweeps every value once, so the valid j's [nums[i], n-1] map to a
// contiguous range of k's: [(i+1)%n, (i-nums[i]+n)%n]. Mark that range
// with a difference array, then prefix-sum to find the best k.
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n) continue; // value too large to ever be reachable as a position
            int lo = (i + 1) % n;
            int hi = (i - nums[i] + n) % n;
            if (lo <= hi) {
                diff[lo]++;
                diff[hi + 1]--;
            } else {
                diff[lo]++;
                diff[n]--;
                diff[0]++;
                diff[hi + 1]--;
            }
        }
        int best = 0, bestScore = INT_MIN, cur = 0;
        for (int k = 0; k < n; k++) {
            cur += diff[k];
            if (cur > bestScore) { bestScore = cur; best = k; }
        }
        return best;
    }
};

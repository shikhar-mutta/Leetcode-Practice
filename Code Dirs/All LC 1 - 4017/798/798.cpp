// Link: https://leetcode.com/problems/smallest-rotation-with-highest-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: after rotating by k, element i moves to position p=(i-k+n)%n and scores iff nums[i] <= p. As p ranges over [nums[i], n-1], k ranges (mod n) over a contiguous block from (i+1)%n to (i-nums[i]+n)%n. Accumulate these ranges into a difference array, then scan for the k with the max prefix sum.
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for (int i = 0; i < n; i++) {
            int kLo = (i + 1) % n;
            int kHi = (i - nums[i] + n) % n;
            if (kLo <= kHi) {
                diff[kLo]++;
                diff[kHi+1]--;
            } else {
                diff[0]++;
                diff[kHi+1]--;
                diff[kLo]++;
                diff[n]--;
            }
        }
        int best = -1, bestK = 0, cur = 0;
        for (int k = 0; k < n; k++) {
            cur += diff[k];
            if (cur > best) { best = cur; bestK = k; }
        }
        return bestK;
    }
};

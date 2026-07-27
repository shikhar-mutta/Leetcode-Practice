// Link: https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 50) SC: O(1)
// Approach: the added x can be any integer, so the operation really means
// "pick a value v and a subarray, turn every v inside it into k". Since
// 1 <= nums[i], k <= 50, brute force every candidate v: map each element
// to +1 (equals v), -1 (equals k), or 0, and take the best (Kadane)
// subarray sum (clamped to >= 0, an empty choice is fine). Answer =
// original count of k + the best gain over all v.
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int countK = 0;
        for (int x : nums) if (x == k) countK++;

        int overallBest = 0;
        for (int v = 1; v <= 50; v++) {
            if (v == k) continue;
            int cur = 0, best = 0;
            for (int x : nums) {
                int gain = (x == v) ? 1 : (x == k ? -1 : 0);
                cur = max(0, cur + gain);
                best = max(best, cur);
            }
            overallBest = max(overallBest, best);
        }
        return countK + overallBest;
    }
};

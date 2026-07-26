// Link: https://leetcode.com/problems/maximize-win-from-two-segments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: since prizePositions is sorted, a two-pointer sliding window
// finds, for each right endpoint, the widest window of length k ending
// there and how many prizes it covers. Track a running prefix-max
// best[i] of the best single segment among the first i prizes; for each
// window, combine its count with the best non-overlapping segment
// entirely before it (best[left]) to get a candidate for two disjoint
// segments, keeping the overall maximum.
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        // best[i] = max prizes coverable by one segment among the first i prizes
        vector<int> best(n + 1, 0);

        int left = 0, res = 0;
        for (int right = 0; right < n; ++right) {
            // shrink window so it fits within length k
            while (prizePositions[right] - prizePositions[left] > k) ++left;
            int windowCount = right - left + 1;

            // best first segment ending before this window starts (non-overlapping)
            res = max(res, windowCount + best[left]);

            // update prefix-max: best single segment among first (right+1) prizes
            best[right + 1] = max(best[right], windowCount);
        }
        return res;
    }
};

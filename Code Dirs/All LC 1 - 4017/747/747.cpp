// Link: https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track largest and second largest; the largest qualifies if it's at least twice the second largest.
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 1; i < (int)nums.size(); i++) if (nums[i] > nums[maxIdx]) maxIdx = i;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i != maxIdx && nums[maxIdx] < 2 * nums[i]) return -1;
        }
        return maxIdx;
    }
};

// Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: single pass tracking current run length, reset when the sequence breaks.
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int best = 1, cur = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i-1]) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best;
    }
};

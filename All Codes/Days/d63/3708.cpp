// Link: https://leetcode.com/problems/longest-fibonacci-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: linear scan tracking the current run length where each
// element equals the sum of the previous two; any single element or
// pair trivially qualifies (length 1 or 2), so reset to 2 whenever the
// triple condition breaks.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int runLen = 2, best = 2;
        for (int i = 2; i < n; i++) {
            if ((long long)nums[i] == (long long)nums[i-1] + nums[i-2]) runLen++;
            else runLen = 2;
            best = max(best, runLen);
        }
        return best;
    }
};

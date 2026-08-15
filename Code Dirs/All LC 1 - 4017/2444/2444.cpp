// Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastMinIdx = -1, lastMaxIdx = -1, lastInvalidIdx = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) lastInvalidIdx = i;
            if (nums[i] == minK) lastMinIdx = i;
            if (nums[i] == maxK) lastMaxIdx = i;
            int leftBound = min(lastMinIdx, lastMaxIdx);
            ans += max(0, leftBound - lastInvalidIdx);
        }
        return ans;
    }
};

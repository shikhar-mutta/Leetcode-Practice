// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log k)  SC: O(k)
// Approach: min-heap of (value, listIdx, elemIdx) with one pointer per
// list, tracking the current max across the heap's top elements.
// Repeatedly pop the min, update the best range [min,max], then advance
// that list's pointer and push its next value (stop if a list is
// exhausted, since the range can no longer include all k lists).
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        int curMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        int bestLo = 0, bestHi = INT_MAX;
        while (true) {
            auto [val, li, ei] = pq.top(); pq.pop();
            if (curMax - val < bestHi - bestLo) { bestLo = val; bestHi = curMax; }
            if (ei + 1 == (int)nums[li].size()) break;
            int nextVal = nums[li][ei + 1];
            curMax = max(curMax, nextVal);
            pq.push({nextVal, li, ei + 1});
        }
        return {bestLo, bestHi};
    }
};

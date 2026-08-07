// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log k) SC: O(k)
// Approach: min-heap of (value, list index, elem index) initialized with first element of each list; track current max; repeatedly pop min, update best range using [min,curMax], advance that list's pointer, push next element (update curMax); stop if any list is exhausted.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        int curMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        int bestLo = pq.top()[0], bestHi = curMax;
        while (true) {
            auto [val, li, ei] = pq.top(); pq.pop();
            if (curMax - val < bestHi - bestLo) { bestLo = val; bestHi = curMax; }
            if (ei+1 == (int)nums[li].size()) break;
            int nval = nums[li][ei+1];
            curMax = max(curMax, nval);
            pq.push({nval, li, ei+1});
        }
        return {bestLo, bestHi};
    }
};

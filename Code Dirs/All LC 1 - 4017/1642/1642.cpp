// Link: https://leetcode.com/problems/furthest-building-you-can-reach/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i + 1 < (int)heights.size(); i++) {
            int diff = heights[i+1] - heights[i];
            if (diff <= 0) continue;
            minHeap.push(diff);
            if ((int)minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();
                if (bricks < 0) return i;
            }
        }
        return heights.size() - 1;
    }
};

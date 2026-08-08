// Link: https://leetcode.com/problems/pour-water/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(units * n) SC: O(1)
// Approach: for each unit of water dropped at k, simulate: first try to flow as far left as possible while descending or level ends at a lower point, then similarly right; settle at the lowest/farthest reachable spot, otherwise stay at k.
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();
        for (int v = 0; v < volume; v++) {
            int best = -1;
            for (int i = k-1; i >= 0; i--) {
                if (heights[i] > heights[i+1]) break;
                if (heights[i] < heights[i+1]) best = i;
            }
            if (best != -1) { heights[best]++; continue; }
            for (int i = k+1; i < n; i++) {
                if (heights[i] > heights[i-1]) break;
                if (heights[i] < heights[i-1]) best = i;
            }
            if (best != -1) { heights[best]++; continue; }
            heights[k]++;
        }
        return heights;
    }
};

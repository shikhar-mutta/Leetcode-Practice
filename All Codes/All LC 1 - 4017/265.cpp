// Link: https://leetcode.com/problems/paint-house-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(k)
// Approach: DP tracking the min and second-min total cost among all colors at the previous house;
// each color at the current house adds its cost to the previous min (or second-min if it was the
// color achieving that min), avoiding an O(k^2) scan per house
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int k = costs[0].size();
        int prevMinIdx = -1, prevMin = 0, prevSecondMin = 0;
        for (auto& row : costs) {
            int curMinIdx = -1, curMin = INT_MAX, curSecondMin = INT_MAX;
            for (int j = 0; j < k; j++) {
                int cost = row[j] + (j == prevMinIdx ? prevSecondMin : prevMin);
                if (cost < curMin) {
                    curSecondMin = curMin;
                    curMin = cost;
                    curMinIdx = j;
                } else if (cost < curSecondMin) {
                    curSecondMin = cost;
                }
            }
            prevMinIdx = curMinIdx;
            prevMin = curMin;
            prevSecondMin = curSecondMin;
        }
        return prevMin;
    }
};

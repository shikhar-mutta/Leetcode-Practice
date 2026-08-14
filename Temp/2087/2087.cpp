// Link: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int total = 0;
        int r = startPos[0], c = startPos[1];
        int step = (homePos[0] >= r) ? 1 : -1;
        while (r != homePos[0]) { r += step; total += rowCosts[r]; }
        step = (homePos[1] >= c) ? 1 : -1;
        while (c != homePos[1]) { c += step; total += colCosts[c]; }
        return total;
    }
};

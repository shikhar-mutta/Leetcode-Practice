// Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long xOverlap = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                long long yOverlap = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                long long side = min(xOverlap, yOverlap);
                if (side > 0) best = max(best, side * side);
            }
        }
        return best;
    }
};

// Link: https://leetcode.com/problems/valid-boomerang/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        long long x1 = points[1][0]-points[0][0], y1 = points[1][1]-points[0][1];
        long long x2 = points[2][0]-points[0][0], y2 = points[2][1]-points[0][1];
        return x1*y2 - x2*y1 != 0;
    }
};

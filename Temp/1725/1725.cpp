// Link: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int best = 0, count = 0;
        for (auto& r : rectangles) {
            int side = min(r[0], r[1]);
            if (side > best) { best = side; count = 1; }
            else if (side == best) count++;
        }
        return count;
    }
};

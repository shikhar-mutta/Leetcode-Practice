// Link: https://leetcode.com/problems/champagne-tower/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(query_row^2) SC: O(query_row)
// Approach: simulate row by row; each glass's overflow (amount above 1) splits evenly to the two glasses below.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double)poured};
        for (int r = 0; r < query_row; r++) {
            vector<double> next(r+2, 0.0);
            for (int c = 0; c <= r; c++) {
                double overflow = (row[c] - 1.0) / 2.0;
                if (overflow > 0) {
                    next[c] += overflow;
                    next[c+1] += overflow;
                }
            }
            row = next;
        }
        return min(1.0, row[query_glass]);
    }
};

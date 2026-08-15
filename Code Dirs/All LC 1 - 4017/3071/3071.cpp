// Link: https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int mid = n / 2;
        vector<int> cntY(3, 0), cntN(3, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isY;
                if (i < mid) isY = (j == i || j == n - 1 - i);
                else isY = (j == mid);
                if (isY) cntY[grid[i][j]]++;
                else cntN[grid[i][j]]++;
            }
        }
        int totalY = cntY[0] + cntY[1] + cntY[2];
        int totalN = cntN[0] + cntN[1] + cntN[2];
        int best = INT_MAX;
        for (int y = 0; y < 3; y++) {
            for (int nn = 0; nn < 3; nn++) {
                if (y == nn) continue;
                int cost = (totalY - cntY[y]) + (totalN - cntN[nn]);
                best = min(best, cost);
            }
        }
        return best;
    }
};

// Link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<int, greater<int>> top3;

        auto addSum = [&](int s) {
            top3.insert(s);
            if (top3.size() > 3) top3.erase(prev(top3.end()));
        };

        for (int cr = 0; cr < rows; cr++) {
            for (int cc = 0; cc < cols; cc++) {
                int maxR = min({cr, cc, rows - 1 - cr, cols - 1 - cc});
                addSum(grid[cr][cc]);
                for (int r = 1; r <= maxR; r++) {
                    long long sum = 0;
                    int x = cr - r, y = cc;
                    for (int i = 0; i < r; i++) { sum += grid[x][y]; x++; y++; }
                    x = cr, y = cc + r;
                    for (int i = 0; i < r; i++) { sum += grid[x][y]; x++; y--; }
                    x = cr + r, y = cc;
                    for (int i = 0; i < r; i++) { sum += grid[x][y]; x--; y--; }
                    x = cr, y = cc - r;
                    for (int i = 0; i < r; i++) { sum += grid[x][y]; x--; y++; }
                    addSum((int)sum);
                }
            }
        }

        return vector<int>(top3.begin(), top3.end());
    }
};

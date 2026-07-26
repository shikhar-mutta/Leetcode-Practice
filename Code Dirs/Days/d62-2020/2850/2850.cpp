// Link: https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k!) where k = number of excess stones (<=9 cells, small in practice)
// SC: O(k)
// Approach: each cell with count > 1 contributes (count-1) separate excess
// stones as sources; each 0-cell is a destination needing one stone. Since
// the grid is fixed 3x3, brute-force every permutation of assigning sources
// to destinations (equal counts guaranteed by total stones == 9) and take
// the min total Manhattan-distance cost.
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> from, to;   // excess sources, deficit destinations

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 1)
                    for (int k = 0; k < grid[i][j] - 1; ++k)
                        from.push_back({i, j});   // each extra stone is a separate source
                else if (grid[i][j] == 0)
                    to.push_back({i, j});
            }

        // try all permutations of matching sources to destinations
        sort(from.begin(), from.end());
        int best = INT_MAX;

        do {
            int cost = 0;
            for (int i = 0; i < to.size(); ++i)
                cost += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            best = min(best, cost);
        } while (next_permutation(from.begin(), from.end()));

        return best == INT_MAX ? 0 : best;
    }
};

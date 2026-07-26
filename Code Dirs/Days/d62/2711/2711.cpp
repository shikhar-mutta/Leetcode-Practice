// Link: https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)
// SC: O(1) extra (fixed 51-size counters, values bounded by grid constraints)
// Approach: process each top-left-to-bottom-right diagonal independently.
// First sweep the whole diagonal into countBelow (every cell "below" the
// start). Then walk it again: remove the current cell from "below" (it's no
// longer strictly below itself), record |above - below| using counts BEFORE
// adding the current cell to "above" (so it excludes itself from both
// counts), then add it to "above" for the next cell. Repeated for every
// diagonal starting on column 0 (rows-major) and every diagonal starting on
// row 0, column>=1 (to cover diagonals starting from the top edge).
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int countAbove[51]{0};
        int countBelow[51]{0};

        vector<vector<int>> answer(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            fill(begin(countAbove), end(countAbove), 0);

            int above = 0;
            int below = 0;

            for (int j = 0; i + j < m && j < n; j++)
                if (countBelow[grid[i + j][j]]++ == 0)
                    below++;

            for (int j = 0; i + j < m && j < n; j++) {
                if (--countBelow[grid[i + j][j]] == 0)
                    below--;

                answer[i + j][j] = abs(above - below);

                if (countAbove[grid[i + j][j]]++ == 0)
                    above++;
            }
        }

        for (int j = 1; j < n; j++) {
            fill(begin(countAbove), end(countAbove), 0);

            int above = 0;
            int below = 0;

            for (int i = 0; i + j < n && i < m; i++)
                if (countBelow[grid[i][i + j]]++ == 0)
                    below++;

            for (int i = 0; i + j < n && i < m; i++) {
                if (--countBelow[grid[i][i + j]] == 0)
                    below--;

                answer[i][i + j] = abs(above - below);

                if (countAbove[grid[i][i + j]]++ == 0)
                    above++;
            }
        }

        return answer;
    }
};

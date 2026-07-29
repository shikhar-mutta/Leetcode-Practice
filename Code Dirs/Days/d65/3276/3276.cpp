// Link: https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V*R) with Kuhn's matching, SC: O(V+R)
// Approach: choosing at most one cell per row with all-distinct values, maximizing sum, is a
// maximum-weight transversal matroid problem (bipartite matching between distinct values and
// rows containing them, weight = the value itself). Since weight only depends on the value
// (not which row it's matched to), a greedy-by-weight approach is optimal: process distinct
// values from largest to smallest, and try to match each into the bipartite graph via an
// augmenting path (Kuhn's algorithm); if successful, add it to the answer.
class Solution {
public:
    unordered_map<int, vector<int>> rowsWithValue;
    vector<int> matchRow;
    vector<bool> visited;

    bool tryAugment(int v) {
        for (int r : rowsWithValue[v]) {
            if (visited[r]) continue;
            visited[r] = true;
            if (matchRow[r] == -1 || tryAugment(matchRow[r])) {
                matchRow[r] = v;
                return true;
            }
        }
        return false;
    }

    int maxScore(vector<vector<int>>& grid) {
        int R = grid.size();
        for (int r = 0; r < R; r++) {
            set<int> seen;
            for (int v : grid[r]) {
                if (seen.insert(v).second) rowsWithValue[v].push_back(r);
            }
        }

        vector<int> values;
        for (auto& [v, rows] : rowsWithValue) values.push_back(v);
        sort(values.begin(), values.end(), greater<int>());

        matchRow.assign(R, -1);
        long long ans = 0;
        for (int v : values) {
            visited.assign(R, false);
            if (tryAugment(v)) ans += v;
        }
        return (int)ans;
    }
};

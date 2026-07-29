// Link: https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dp(m, vector<long long>(n, INF));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) { dp[i][j] = 0; continue; }
                long long best = INF;
                if (i > 0) best = min(best, dp[i-1][j] + grid[i][j]);
                if (j > 0) best = min(best, dp[i][j-1] + grid[i][j]);
                dp[i][j] = best;
            }
        }

        long long ans = dp[m-1][n-1];

        for (int t = 1; t <= k; t++) {
            // build sorted-by-grid-desc list of previous level's dp values
            vector<pair<int,long long>> cells; // (grid value, dp value)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cells.push_back({grid[i][j], dp[i][j]});
            sort(cells.begin(), cells.end(), [](auto& a, auto& b){ return a.first > b.first; });
            vector<long long> prefMin(cells.size());
            prefMin[0] = cells[0].second;
            for (size_t idx = 1; idx < cells.size(); idx++) prefMin[idx] = min(prefMin[idx-1], cells[idx].second);
            vector<int> sortedVals(cells.size());
            for (size_t idx = 0; idx < cells.size(); idx++) sortedVals[idx] = cells[idx].first;

            vector<vector<long long>> ndp(m, vector<long long>(n, INF));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // find last index with value >= grid[i][j] (sortedVals descending)
                    int lo = 0, hi = (int)sortedVals.size() - 1, resIdx = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (sortedVals[mid] >= grid[i][j]) { resIdx = mid; lo = mid + 1; }
                        else hi = mid - 1;
                    }
                    long long seed = (resIdx == -1) ? INF : prefMin[resIdx];

                    long long best = seed;
                    if (i > 0) best = min(best, ndp[i-1][j] + grid[i][j]);
                    if (j > 0) best = min(best, ndp[i][j-1] + grid[i][j]);
                    ndp[i][j] = best;
                }
            }

            dp = ndp;
            ans = min(ans, dp[m-1][n-1]);
        }

        return (int)ans;
    }
};

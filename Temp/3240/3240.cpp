// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int quadCost = 0;
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < m/2; j++) {
                int ones = grid[i][j] + grid[i][m-1-j] + grid[n-1-i][j] + grid[n-1-i][m-1-j];
                quadCost += min(ones, 4 - ones);
            }
        }

        const int INF = INT_MAX / 2;
        vector<int> dp(4, INF);
        dp[0] = 0;

        auto addItem = [&](vector<pair<int,int>>& options) {
            // options: list of (cost, residueAdded)
            vector<int> ndp(4, INF);
            for (int r = 0; r < 4; r++) {
                if (dp[r] >= INF) continue;
                for (auto& [cost, add] : options) {
                    int nr = (r + add) % 4;
                    ndp[nr] = min(ndp[nr], dp[r] + cost);
                }
            }
            dp = ndp;
        };

        if (n % 2 == 1) {
            int mid = n / 2;
            for (int j = 0; j < m/2; j++) {
                int a = grid[mid][j], b = grid[mid][m-1-j];
                vector<pair<int,int>> opts;
                if (a == b) {
                    opts.push_back({0, (2*a) % 4});
                    opts.push_back({2, (2*(1-a)) % 4});
                } else {
                    opts.push_back({1, 0});
                    opts.push_back({1, 2});
                }
                addItem(opts);
            }
        }

        if (m % 2 == 1) {
            int mid = m / 2;
            for (int i = 0; i < n/2; i++) {
                int a = grid[i][mid], b = grid[n-1-i][mid];
                vector<pair<int,int>> opts;
                if (a == b) {
                    opts.push_back({0, (2*a) % 4});
                    opts.push_back({2, (2*(1-a)) % 4});
                } else {
                    opts.push_back({1, 0});
                    opts.push_back({1, 2});
                }
                addItem(opts);
            }
        }

        if (n % 2 == 1 && m % 2 == 1) {
            int v = grid[n/2][m/2];
            vector<pair<int,int>> opts;
            opts.push_back({0, v});
            opts.push_back({1, 1 - v});
            addItem(opts);
        }

        return quadCost + dp[0];
    }
};

// Link: https://leetcode.com/problems/paint-house-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = INT_MAX / 2;
    vector<vector<vector<int>>> memo;

    int dfs(int i, int prevColor, int groups, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        if (groups > target) return INF;
        if (i == m) return groups == target ? 0 : INF;
        if (memo[i][prevColor][groups] != -1) return memo[i][prevColor][groups];

        int best = INF;
        if (houses[i] != 0) {
            int color = houses[i];
            int newGroups = groups + (color != prevColor ? 1 : 0);
            best = dfs(i + 1, color, newGroups, houses, cost, m, n, target);
        } else {
            for (int color = 1; color <= n; color++) {
                int newGroups = groups + (color != prevColor ? 1 : 0);
                int c = cost[i][color - 1] + dfs(i + 1, color, newGroups, houses, cost, m, n, target);
                best = min(best, c);
            }
        }
        memo[i][prevColor][groups] = best;
        return best;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memo.assign(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int res = dfs(0, 0, 0, houses, cost, m, n, target);
        return res >= INF ? -1 : res;
    }
};

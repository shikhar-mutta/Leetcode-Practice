// Link: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size(), size2 = cost[0].size();
        vector<int> minCost2(size2, INT_MAX);
        for (int j = 0; j < size2; j++)
            for (int i = 0; i < size1; i++)
                minCost2[j] = min(minCost2[j], cost[i][j]);

        int full = 1 << size2;
        vector<vector<int>> memo(size1 + 1, vector<int>(full, -1));

        function<int(int,int)> dfs = [&](int i, int mask) -> int {
            if (i == size1) {
                int sum = 0;
                for (int j = 0; j < size2; j++) if (!(mask & (1 << j))) sum += minCost2[j];
                return sum;
            }
            if (memo[i][mask] != -1) return memo[i][mask];
            int best = INT_MAX;
            for (int j = 0; j < size2; j++) {
                best = min(best, cost[i][j] + dfs(i + 1, mask | (1 << j)));
            }
            memo[i][mask] = best;
            return best;
        };

        return dfs(0, 0);
    }
};

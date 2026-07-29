// Link: https://leetcode.com/problems/maximum-profit-from-valid-topological-order-in-dag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> pred(n, 0);
        for (auto& e : edges) pred[e[1]] |= (1 << e[0]);

        int full = 1 << n;
        vector<long long> dp(full, -1);
        dp[0] = 0;

        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] < 0) continue;
            int pos = __builtin_popcount(mask) + 1;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                if ((pred[v] & mask) != pred[v]) continue;
                int nmask = mask | (1 << v);
                long long val = dp[mask] + (long long)score[v] * pos;
                if (val > dp[nmask]) dp[nmask] = val;
            }
        }

        return (int)dp[full - 1];
    }
};

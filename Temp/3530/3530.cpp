// Link: https://leetcode.com/problems/maximum-profit-from-valid-topological-order-in-dag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> predMask(n, 0);
        for (auto& e : edges) {
            predMask[e[1]] |= (1 << e[0]);
        }

        int full = 1 << n;
        vector<long long> dp(full, -1);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] < 0) continue;
            int pos = __builtin_popcount(mask) + 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                if ((predMask[i] & mask) != predMask[i]) continue;
                int nmask = mask | (1 << i);
                long long cand = dp[mask] + (long long)score[i] * pos;
                if (cand > dp[nmask]) dp[nmask] = cand;
            }
        }

        return (int)dp[full - 1];
    }
};

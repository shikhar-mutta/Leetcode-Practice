// Link: https://leetcode.com/problems/stone-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i+1] + piles[i];

        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        function<int(int,int)> dfs = [&](int i, int m) {
            if (i >= n) return 0;
            if (i + 2 * m >= n) return suffix[i];
            if (memo[i][m] != -1) return memo[i][m];
            int best = 0;
            for (int x = 1; x <= 2 * m; x++) {
                best = max(best, suffix[i] - dfs(i + x, max(m, x)));
            }
            return memo[i][m] = best;
        };
        return dfs(0, 1);
    }
};

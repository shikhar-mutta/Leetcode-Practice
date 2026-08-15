// Link: https://leetcode.com/problems/stone-game-v/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stoneValue[i];
        auto sum = [&](int l, int r) { return prefix[r+1] - prefix[l]; };

        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (i == j) return 0;
            if (memo[i][j] != -1) return memo[i][j];
            int best = 0;
            for (int k = i; k < j; k++) {
                int leftSum = sum(i, k), rightSum = sum(k+1, j);
                if (leftSum < rightSum) best = max(best, leftSum + dfs(i, k));
                else if (leftSum > rightSum) best = max(best, rightSum + dfs(k+1, j));
                else best = max(best, leftSum + max(dfs(i, k), dfs(k+1, j)));
            }
            memo[i][j] = best;
            return best;
        };
        return dfs(0, n - 1);
    }
};

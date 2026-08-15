// Link: https://leetcode.com/problems/painting-the-walls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        function<int(int,int)> solve = [&](int i, int need) -> int {
            if (need <= 0) return 0;
            if (i == n) return INT_MAX / 2;
            if (dp[i][need] != -1) return dp[i][need];

            int skip = solve(i + 1, need);
            int take = cost[i] + solve(i + 1, max(0, need - 1 - time[i]));
            return dp[i][need] = min(skip, take);
        };

        return solve(0, n);
    }
};

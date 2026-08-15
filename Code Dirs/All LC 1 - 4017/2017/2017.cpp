// Link: https://leetcode.com/problems/grid-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = 0, bottomSum = 0;
        for (int i = 0; i < n; i++) topSum += grid[0][i];
        long long ans = LLONG_MAX;
        long long bottomPrefix = 0;
        for (int i = 0; i < n; i++) {
            topSum -= grid[0][i];
            long long robot2 = max(topSum, bottomPrefix);
            ans = min(ans, robot2);
            bottomPrefix += grid[1][i];
        }
        return ans;
    }
};

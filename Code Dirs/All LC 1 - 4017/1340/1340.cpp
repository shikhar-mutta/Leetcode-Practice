// Link: https://leetcode.com/problems/jump-game-v/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);

        function<int(int)> dfs = [&](int i) -> int {
            if (memo[i] != -1) return memo[i];
            int best = 1;
            for (int dir = -1; dir <= 1; dir += 2) {
                for (int step = 1; step <= d; step++) {
                    int ni = i + dir * step;
                    if (ni < 0 || ni >= n) break;
                    if (arr[ni] >= arr[i]) break;
                    best = max(best, 1 + dfs(ni));
                }
            }
            memo[i] = best;
            return best;
        };

        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, dfs(i));
        return res;
    }
};

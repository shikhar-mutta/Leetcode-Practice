// Link: https://leetcode.com/problems/count-all-possible-routes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        memo.assign(n, vector<int>(fuel + 1, -1));
        function<int(int,int)> dfs = [&](int cur, int f) -> int {
            if (memo[cur][f] != -1) return memo[cur][f];
            long long ways = (cur == finish) ? 1 : 0;
            for (int nxt = 0; nxt < n; nxt++) {
                if (nxt == cur) continue;
                int cost = abs(locations[cur] - locations[nxt]);
                if (cost <= f) ways = (ways + dfs(nxt, f - cost)) % MOD;
            }
            return memo[cur][f] = (int)ways;
        };
        return dfs(start, fuel);
    }
};

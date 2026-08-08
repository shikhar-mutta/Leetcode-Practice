// Link: https://leetcode.com/problems/count-all-possible-routes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<int>> memo;

    long long dfs(vector<int>& locations, int cur, int finish, int fuel) {
        if (fuel < 0) return 0;
        if (memo[cur][fuel] != -1) return memo[cur][fuel];

        long long ways = (cur == finish) ? 1 : 0;
        for (int next = 0; next < (int)locations.size(); next++) {
            if (next == cur) continue;
            int cost = abs(locations[cur] - locations[next]);
            if (cost <= fuel) {
                ways = (ways + dfs(locations, next, finish, fuel - cost)) % MOD;
            }
        }
        memo[cur][fuel] = (int)ways;
        return ways;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        memo.assign(n, vector<int>(fuel + 1, -1));
        return (int)dfs(locations, start, finish, fuel);
    }
};

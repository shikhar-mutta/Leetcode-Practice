// Link: https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<int>> adj;
    vector<long long> fact, invFact;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    pair<long long,long long> dfs(int u) {
        // returns {subtreeSize, ways}
        long long size = 1, ways = 1;
        for (int v : adj[u]) {
            auto [csize, cways] = dfs(v);
            ways = ways * cways % MOD;
            ways = ways * invFact[csize] % MOD;
            size += csize;
        }
        ways = ways * fact[size - 1] % MOD;
        return {size, ways};
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        adj.assign(n, vector<int>());
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (prevRoom[i] == -1) root = i;
            else adj[prevRoom[i]].push_back(i);
        }
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact.assign(n + 1, 1);
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        return (int)dfs(root).second;
    }
};

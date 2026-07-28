// Link: https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: tree topological-order counting. For each node, DFS children,
// combine their (size, ways) via multinomial merge: interleaving two ordered
// sequences of length a,b has C(a+b,b) ways, applied incrementally while
// accumulating subtree size, multiplied by each child's own internal ways.
class Solution {
    const long long MOD = 1e9 + 7;
    vector<long long> fact, invfact;
    vector<vector<int>> children;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }
    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    }

    pair<long long,long long> dfs(int u) { // returns (subtreeSize, ways)
        long long total = 0, ways = 1; // total = combined size of children processed so far (excludes root)
        for (int c : children[u]) {
            auto [cs, cw] = dfs(c);
            ways = ways * cw % MOD * C((int)(total + cs), (int)cs) % MOD;
            total += cs;
        }
        return {total + 1, ways};
    }
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        children.assign(n, {});
        for (int i = 1; i < n; i++) children[prevRoom[i]].push_back(i);
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invfact.assign(n + 1, 1);
        invfact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;

        auto [size, ways] = dfs(0);
        return (int)ways;
    }
};

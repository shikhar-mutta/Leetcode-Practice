// Link: https://leetcode.com/problems/count-valid-paths-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long long)i * i <= n; i++)
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;

        vector<int> compId(n + 1, -1);
        vector<long long> compSize;
        for (int i = 1; i <= n; i++) {
            if (isPrime[i] || compId[i] != -1) continue;
            int id = compSize.size();
            long long sz = 0;
            queue<int> q;
            q.push(i);
            compId[i] = id;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                sz++;
                for (int v : adj[u]) {
                    if (!isPrime[v] && compId[v] == -1) {
                        compId[v] = id;
                        q.push(v);
                    }
                }
            }
            compSize.push_back(sz);
        }

        long long ans = 0;
        for (int p = 1; p <= n; p++) {
            if (!isPrime[p]) continue;
            long long total = 0, sumSq = 0;
            for (int v : adj[p]) {
                if (!isPrime[v]) {
                    long long sz = compSize[compId[v]];
                    total += sz;
                    sumSq += sz * sz;
                }
            }
            ans += total + (total * total - sumSq) / 2;
        }
        return ans;
    }
};

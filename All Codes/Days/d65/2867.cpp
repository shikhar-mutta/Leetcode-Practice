// Link: https://leetcode.com/problems/count-valid-paths-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log log N), SC: O(N)
// Approach: sieve primes up to n. Group the non-prime nodes into connected components (edges
// between two non-prime nodes only) and record each component's size. For every prime node p,
// treat each non-prime-neighbor's component size as a "branch reach"; valid paths through p with
// exactly one prime are: (p paired with each reachable node) + (cross-branch pairs), computed
// from the sum and sum-of-squares of the branch sizes.
class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> isComposite(n+1, false);
        isComposite[1] = true;
        for (int i = 2; (long long)i * i <= n; i++)
            if (!isComposite[i])
                for (long long j = (long long)i*i; j <= n; j += i) isComposite[j] = true;
        auto isPrime = [&](int x) { return x > 1 && !isComposite[x]; };

        vector<vector<int>> adj(n+1);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        vector<int> compId(n+1, -1), compSize;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i) || compId[i] != -1) continue;
            int id = compSize.size();
            int size = 0;
            queue<int> q; q.push(i); compId[i] = id;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                size++;
                for (int v : adj[u]) {
                    if (isPrime(v) || compId[v] != -1) continue;
                    compId[v] = id;
                    q.push(v);
                }
            }
            compSize.push_back(size);
        }

        long long ans = 0;
        for (int p = 1; p <= n; p++) {
            if (!isPrime(p)) continue;
            long long S = 0, sumSq = 0;
            for (int v : adj[p]) {
                if (isPrime(v)) continue;
                long long sz = compSize[compId[v]];
                S += sz;
                sumSq += sz * sz;
            }
            ans += S + (S*S - sumSq) / 2;
        }
        return ans;
    }
};

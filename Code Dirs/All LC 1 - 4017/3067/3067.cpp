// Link: https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> ans(n, 0);
        for (int root = 0; root < n; root++) {
            long long total = 0;
            long long sumCnt = 0;
            for (auto& [child, w] : adj[root]) {
                // BFS/DFS in this child's subtree (excluding root)
                long long cnt = 0;
                stack<pair<int,long long>> st;
                st.push({child, w});
                vector<bool> vis(n, false);
                vis[root] = true;
                vis[child] = true;
                if (w % signalSpeed == 0) cnt++;
                while (!st.empty()) {
                    auto [u, dist] = st.top(); st.pop();
                    for (auto& [v, w2] : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            long long nd = dist + w2;
                            if (nd % signalSpeed == 0) cnt++;
                            st.push({v, nd});
                        }
                    }
                }
                total += sumCnt * cnt;
                sumCnt += cnt;
            }
            ans[root] = (int)total;
        }
        return ans;
    }
};

// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

class DistanceLimitedPathsExist {
public:
    int n;
    vector<int> dsu;
    vector<int> nodeVal;
    vector<vector<int>> children;
    vector<int> depth;
    vector<vector<int>> up;
    int LOG;
    int totalNodes;

    int find(int x) {
        while (dsu[x] != x) { dsu[x] = dsu[dsu[x]]; x = dsu[x]; }
        return x;
    }

    DistanceLimitedPathsExist(int n_, vector<vector<int>>& edgeList) {
        n = n_;
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int maxNodes = 2 * n;
        dsu.resize(maxNodes);
        nodeVal.assign(maxNodes, 0);
        children.assign(maxNodes, vector<int>());
        for (int i = 0; i < maxNodes; i++) dsu[i] = i;

        int nextNode = n;
        for (auto& e : edgeList) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) continue;
            int newNode = nextNode++;
            nodeVal[newNode] = e[2];
            children[newNode].push_back(a);
            children[newNode].push_back(b);
            dsu[a] = newNode;
            dsu[b] = newNode;
            dsu[newNode] = newNode;
        }
        totalNodes = nextNode;

        LOG = 1;
        while ((1 << LOG) < totalNodes + 1) LOG++;
        up.assign(totalNodes, vector<int>(LOG, -1));
        depth.assign(totalNodes, 0);

        vector<bool> visited(totalNodes, false);
        for (int i = 0; i < totalNodes; i++) {
            if (find(i) == i && !visited[i]) {
                dfsBuild(i, -1, 0, visited);
            }
        }
    }

    void dfsBuild(int node, int parent, int d, vector<bool>& visited) {
        visited[node] = true;
        depth[node] = d;
        up[node][0] = parent;
        for (int j = 1; j < LOG; j++) {
            if (up[node][j-1] != -1) up[node][j] = up[up[node][j-1]][j-1];
        }
        for (int c : children[node]) dfsBuild(c, node, d + 1, visited);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) if ((diff >> j) & 1) u = up[u][j];
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) { u = up[u][j]; v = up[v][j]; }
        }
        return up[u][0];
    }

    bool query(int p, int q, int limit) {
        if (p == q) return true;
        int a = lca(p, q);
        return nodeVal[a] < limit;
    }
};

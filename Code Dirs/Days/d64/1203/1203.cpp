// Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n + edges)  SC: O(n + edges)
// Approach: two-level topological sort. Items with group -1 each get
// their own fresh unique group id. Topologically sort items by their
// beforeItems dependencies (Kahn's algorithm); separately topologically
// sort groups by dependencies derived from cross-group item edges.
// Bucket the item-topo-order items by group (preserving relative order
// within each group), then concatenate buckets in group-topo order.
class Solution {
    vector<int> topoSort(int n, vector<vector<int>>& adj) {
        vector<int> indeg(n, 0);
        for (int u = 0; u < n; u++) for (int v : adj[u]) indeg[v]++;
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
        }
        if ((int)order.size() != n) return {};
        return order;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupCount = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) group[i] = groupCount++;
        }

        vector<vector<int>> itemAdj(n);
        vector<vector<int>> groupAdj(groupCount);

        for (int i = 0; i < n; i++) {
            for (int b : beforeItems[i]) {
                itemAdj[b].push_back(i);
                if (group[b] != group[i]) {
                    groupAdj[group[b]].push_back(group[i]);
                }
            }
        }

        vector<int> itemOrder = topoSort(n, itemAdj);
        if (itemOrder.empty() && n > 0) return {};
        vector<int> groupOrder = topoSort(groupCount, groupAdj);
        if (groupOrder.empty() && groupCount > 0) return {};

        vector<vector<int>> bucket(groupCount);
        for (int item : itemOrder) bucket[group[item]].push_back(item);

        vector<int> ans;
        for (int g : groupOrder) for (int item : bucket[g]) ans.push_back(item);
        return ans;
    }
};

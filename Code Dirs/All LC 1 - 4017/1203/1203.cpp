// Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupCount = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) group[i] = groupCount++;
        }

        vector<vector<int>> itemGraph(n);
        vector<int> itemIndeg(n, 0);
        vector<vector<int>> groupGraph(groupCount);
        vector<int> groupIndeg(groupCount, 0);
        set<pair<int,int>> groupEdges;

        for (int i = 0; i < n; i++) {
            for (int b : beforeItems[i]) {
                itemGraph[b].push_back(i);
                itemIndeg[i]++;
                if (group[b] != group[i]) {
                    auto edge = make_pair(group[b], group[i]);
                    if (!groupEdges.count(edge)) {
                        groupEdges.insert(edge);
                        groupGraph[group[b]].push_back(group[i]);
                        groupIndeg[group[i]]++;
                    }
                }
            }
        }

        auto topoSort = [](vector<vector<int>>& graph, vector<int>& indeg, int count) -> vector<int> {
            vector<int> order;
            queue<int> q;
            for (int i = 0; i < count; i++) if (indeg[i] == 0) q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int v : graph[u]) {
                    if (--indeg[v] == 0) q.push(v);
                }
            }
            return order;
        };

        vector<int> itemOrder = topoSort(itemGraph, itemIndeg, n);
        if ((int)itemOrder.size() != n) return {};
        vector<int> groupOrder = topoSort(groupGraph, groupIndeg, groupCount);
        if ((int)groupOrder.size() != groupCount) return {};

        vector<int> groupPos(groupCount);
        for (int i = 0; i < groupCount; i++) groupPos[groupOrder[i]] = i;

        vector<vector<int>> itemsByGroup(groupCount);
        for (int item : itemOrder) itemsByGroup[group[item]].push_back(item);

        vector<int> res;
        for (int g = 0; g < groupCount; g++) {
            int gid = groupOrder[g];
            for (int item : itemsByGroup[gid]) res.push_back(item);
        }
        return res;
    }
};

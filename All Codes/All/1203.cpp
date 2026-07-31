// Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(n + m)
//  Approach: Topological sort on both the group graph and the item graph.
//  1. Assign unique group ids to items with no group.
//  2. Build the group graph and item graph, and compute indegrees.
//  3. Topologically sort the group graph and item graph.
//  4. If either sort fails (cycle detected), return an empty array.
//  5. Otherwise, combine the sorted items by group order to produce the final result.
//  6. Return the final sorted array of items.
class Solution
{

    vector<int> topologicalSort(vector<int> &indegree,
                                vector<vector<int>> &adj)
    {
        int n = indegree.size();
        vector<int> sorted(n, -1);
        int k = n - 1;
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            sorted[k--] = node;
            for (int nextNode : adj[node])
            {
                indegree[nextNode]--;
                if (indegree[nextNode] == 0)
                    q.push(nextNode);
            }
        }
        if (k != -1)
            return {};
        return sorted;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group,
                          vector<vector<int>> &beforeItems)
    {
        int id = m;
        vector<int> nodeIndegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
                group[i] = id++;
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                nodeIndegree[beforeItems[i][j]]++;
            }
        }

        vector<vector<int>> groupGraph(id);
        vector<int> groupIndegree(id, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                if (group[i] == group[beforeItems[i][j]])
                    continue;
                groupGraph[group[i]].push_back(group[beforeItems[i][j]]);
                groupIndegree[group[beforeItems[i][j]]]++;
            }
        }

        vector<int> sortedNodes = topologicalSort(nodeIndegree, beforeItems);
        if (sortedNodes.size() != n)
            return {};
        vector<int> sortedGroups = topologicalSort(groupIndegree, groupGraph);
        if (sortedGroups.size() != id)
            return {};

        vector<vector<int>> sortedNodesByGroup(id);
        for (int node : sortedNodes)
        {
            sortedNodesByGroup[group[node]].push_back(node);
        }

        vector<int> ans;
        for (int group : sortedGroups)
        {
            for (int node : sortedNodesByGroup[group])
                ans.push_back(node);
        }

        return ans;
    }
};
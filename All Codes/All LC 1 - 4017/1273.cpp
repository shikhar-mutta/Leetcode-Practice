// Link: https://leetcode.com/problems/delete-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> children(nodes);
        int root = 0;
        for (int i = 0; i < nodes; i++) {
            if (parent[i] == -1) root = i;
            else children[parent[i]].push_back(i);
        }

        function<pair<int,int>(int)> dfs = [&](int node) -> pair<int,int> {
            int sum = value[node], cnt = 1;
            for (int child : children[node]) {
                auto [s, c] = dfs(child);
                sum += s;
                cnt += c;
            }
            if (sum == 0) return {0, 0};
            return {sum, cnt};
        };

        return dfs(root).second;
    }
};

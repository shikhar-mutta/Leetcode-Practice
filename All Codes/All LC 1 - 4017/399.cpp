// Link: https://leetcode.com/problems/evaluate-division/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((E+Q) * V)  SC: O(V+E)
// Approach: build weighted graph (a/b = v means edge a->b weight v, b->a
// weight 1/v), DFS from query source to target multiplying edge weights
class Solution {
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& cur, const string& target, unordered_set<string>& visited) {
        if (cur == target) return 1.0;
        visited.insert(cur);
        for (auto& [next, weight] : graph[cur]) {
            if (visited.count(next)) continue;
            double res = dfs(next, target, visited);
            if (res >= 0) return res * weight;
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < (int)equations.size(); i++) {
            string& a = equations[i][0];
            string& b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }

        vector<double> res;
        for (auto& q : queries) {
            if (!graph.count(q[0]) || !graph.count(q[1])) { res.push_back(-1.0); continue; }
            unordered_set<string> visited;
            res.push_back(dfs(q[0], q[1], visited));
        }
        return res;
    }
};

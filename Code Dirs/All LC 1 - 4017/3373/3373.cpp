// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> colorTree(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        queue<int> q;
        color[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
            }
        }
        return color;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) { adj1[e[0]].push_back(e[1]); adj1[e[1]].push_back(e[0]); }
        for (auto& e : edges2) { adj2[e[0]].push_back(e[1]); adj2[e[1]].push_back(e[0]); }

        vector<int> color1 = colorTree(adj1);
        vector<int> color2 = colorTree(adj2);

        int cnt1_0 = 0, cnt1_1 = 0;
        for (int c : color1) if (c == 0) cnt1_0++; else cnt1_1++;
        int cnt2_0 = 0, cnt2_1 = 0;
        for (int c : color2) if (c == 0) cnt2_0++; else cnt2_1++;

        int maxTree2 = max(cnt2_0, cnt2_1);

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int sameParity = (color1[i] == 0) ? cnt1_0 : cnt1_1;
            res[i] = sameParity + maxTree2;
        }
        return res;
    }
};

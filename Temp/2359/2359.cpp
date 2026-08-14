// Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distances(vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int cur = start, d = 0;
        while (cur != -1 && dist[cur] == -1) {
            dist[cur] = d++;
            cur = edges[cur];
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto d1 = distances(edges, node1);
        auto d2 = distances(edges, node2);
        int n = edges.size();
        int best = -1, bestMax = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (d1[i] == -1 || d2[i] == -1) continue;
            int m = max(d1[i], d2[i]);
            if (m < bestMax) { bestMax = m; best = i; }
        }
        return best;
    }
};

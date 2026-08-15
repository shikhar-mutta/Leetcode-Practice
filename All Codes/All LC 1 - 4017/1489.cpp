// Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }

    // returns MST weight, or -1 if disconnected; skipIdx excluded, forceIdx pre-included
    int mstWeight(int n, vector<vector<int>>& idxEdges, int skipIdx, int forceIdx) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        int weight = 0, count = 0;

        if (forceIdx != -1) {
            unite(idxEdges[forceIdx][0], idxEdges[forceIdx][1]);
            weight += idxEdges[forceIdx][2];
            count++;
        }
        for (int i = 0; i < (int)idxEdges.size(); i++) {
            if (i == skipIdx || i == forceIdx) continue;
            if (unite(idxEdges[i][0], idxEdges[i][1])) {
                weight += idxEdges[i][2];
                count++;
            }
        }
        return (count == n - 1) ? weight : -1;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> idxEdges(m);
        for (int i = 0; i < m; i++) idxEdges[i] = edges[i];
        for (int i = 0; i < m; i++) idxEdges[i].push_back(i);

        sort(idxEdges.begin(), idxEdges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int baseline = mstWeight(n, idxEdges, -1, -1);

        vector<int> critical, pseudo;
        for (int i = 0; i < m; i++) {
            int origIdx = idxEdges[i][3];
            int withoutW = mstWeight(n, idxEdges, i, -1);
            if (withoutW == -1 || withoutW > baseline) {
                critical.push_back(origIdx);
            } else {
                int withW = mstWeight(n, idxEdges, -1, i);
                if (withW == baseline) pseudo.push_back(origIdx);
            }
        }
        return {critical, pseudo};
    }
};

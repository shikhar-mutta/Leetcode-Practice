// Link: https://leetcode.com/problems/find-champion-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + e) – one pass over edges, one pass over n nodes
// SC: O(n)     – inDegree array of size n
// Approach: In a DAG where every stronger team beats every weaker one,
// the champion must have in-degree 0 (no team beats it). Count in-degrees
// from edges. If exactly one node has in-degree 0, it's the champion;
// if more than one has in-degree 0, return -1 (ambiguous / no unique champion).
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        int winner = -1;
        for (const auto& edge: edges) {
            ++inDegree[edge[1]];
        }
        for (int u = 0; u < n; ++u) {
            if (!inDegree[u]) {
                if (winner != -1) { return -1; }
                winner = u;
            }
        }
        return winner;
    }
};
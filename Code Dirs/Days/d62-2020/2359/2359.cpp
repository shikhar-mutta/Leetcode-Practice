// Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: since each node has at most one outgoing edge, each of node1
// and node2 traces out a single deterministic path (not a branching BFS).
// Walk both paths one step at a time in lockstep, marking visited nodes
// separately per side. At each step (distance t from each start), check
// whether the current node1 position has already been visited by node2's
// path so far, or vice versa - the first such match found gives the
// minimum possible max(dist1, dist2), and comparing both simultaneous
// matches picks the smaller index on a tie. A path that loops back on
// itself (functional graph cycle) or hits a dead end (-1) stops advancing
// on that side.
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<bool> visited1(edges.size(), false);
        visited1[node1] = true;
        vector<bool> visited2(edges.size(), false);
        visited2[node2] = true;


        while (!(node1 == -1 && node2 == -1)) {
            int minMatch = INT_MAX;
            if (node1 != -1 && visited2[node1]) {
                minMatch = min(node1, minMatch);
            }
            if (node2 != -1 && visited1[node2]) {
                minMatch = min(node2, minMatch);
            }
            if (minMatch != INT_MAX) {
                return minMatch;
            }
            if (node1 != -1) {
                if (edges[node1] != -1 && visited1[edges[node1]]) {
                    node1 = -1;
                } else {
                    node1 = edges[node1];
                    if (node1 != -1) {
                        visited1[node1] = true;
                    }
                }
            }
            if (node2 != -1) {
                if (edges[node2] != -1 && visited2[edges[node2]]) {
                    node2 = -1;
                } else {
                    node2 = edges[node2];
                    if (node2 != -1) {
                        visited2[node2] = true;
                    }
                }
            }
        }
        return -1;
    }
};

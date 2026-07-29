// Link: https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: functional graph (each node has <=1 outgoing edge). Walk from each unvisited node
// recording step index; if we re-hit a node from the current walk, cycle length = curStep - itsStep.
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0), runId(n, -1), stepOf(n, -1);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int cur = i, step = 0;
            while (cur != -1 && !visited[cur]) {
                visited[cur] = 1;
                runId[cur] = i;
                stepOf[cur] = step++;
                cur = edges[cur];
            }
            if (cur != -1 && runId[cur] == i) {
                ans = max(ans, step - stepOf[cur]);
            }
        }
        return ans;
    }
};

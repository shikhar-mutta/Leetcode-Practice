// Link: https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, -1), state(n, 0); // 0=unvisited,1=inProgress,2=done
        vector<int> posInPath(n, -1);
        for (int i = 0; i < n; i++) {
            if (state[i] != 0) continue;
            vector<int> path;
            int u = i;
            while (state[u] == 0) {
                state[u] = 1;
                posInPath[u] = path.size();
                path.push_back(u);
                u = edges[u];
            }
            if (state[u] == 1) {
                int idx = posInPath[u];
                int cycleLen = path.size() - idx;
                for (int j = idx; j < (int)path.size(); j++) {
                    ans[path[j]] = cycleLen;
                    state[path[j]] = 2;
                }
                for (int j = idx - 1; j >= 0; j--) {
                    ans[path[j]] = ans[path[j + 1]] + 1;
                    state[path[j]] = 2;
                }
            } else {
                int val = ans[u];
                for (int j = (int)path.size() - 1; j >= 0; j--) {
                    val++;
                    ans[path[j]] = val;
                    state[path[j]] = 2;
                }
            }
        }
        return ans;
    }
};

// Link: https://leetcode.com/problems/finish-time-of-tasks-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: post-order traversal of the tree (iterative to avoid stack
// overflow on chain-shaped trees). Leaf finish time = baseTime; for a
// non-leaf, combine children's finish times via earliest/latest, then
// apply the given ownDuration formula.
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> children(n);
        for (auto& e : edges) children[e[0]].push_back(e[1]);

        vector<long long> finish(n, -1);
        vector<int> parentOrder;
        vector<int> stack = {0};
        while (!stack.empty()) {
            int u = stack.back(); stack.pop_back();
            parentOrder.push_back(u);
            for (int v : children[u]) stack.push_back(v);
        }
        for (int i = (int)parentOrder.size() - 1; i >= 0; i--) {
            int u = parentOrder[i];
            if (children[u].empty()) {
                finish[u] = baseTime[u];
            } else {
                long long earliest = LLONG_MAX, latest = LLONG_MIN;
                for (int v : children[u]) {
                    earliest = min(earliest, finish[v]);
                    latest = max(latest, finish[v]);
                }
                long long ownDuration = (latest - earliest) + baseTime[u];
                finish[u] = latest + ownDuration;
            }
        }
        return finish[0];
    }
};

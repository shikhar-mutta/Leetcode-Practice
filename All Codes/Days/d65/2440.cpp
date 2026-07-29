// Link: https://leetcode.com/problems/create-components-with-same-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2) worst case, SC: O(N)
// Approach: try number of parts k from N down to 1; target = totalSum/k must be integer and
// >= max(nums). DFS the tree: subtree sum resets to 0 (a cut) whenever it hits target exactly,
// fails if it ever exceeds target. First feasible k gives answer k-1 (edges removed).
class Solution {
public:
    vector<vector<int>> adj;
    vector<int>* nums;
    int target;
    bool ok;

    int dfs(int u, int p) {
        int sum = (*nums)[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            sum += dfs(v, u);
            if (!ok) return 0;
        }
        if (sum > target) { ok = false; return 0; }
        return sum == target ? 0 : sum;
    }

    int componentValue(vector<int>& nums_, vector<vector<int>>& edges) {
        int n = nums_.size();
        nums = &nums_;
        adj.assign(n, {});
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        int total = accumulate(nums_.begin(), nums_.end(), 0);
        int mx = *max_element(nums_.begin(), nums_.end());

        for (int k = n; k >= 1; k--) {
            if (total % k != 0) continue;
            target = total / k;
            if (target < mx) continue;
            ok = true;
            dfs(0, -1);
            if (ok) return k - 1;
        }
        return 0;
    }
};

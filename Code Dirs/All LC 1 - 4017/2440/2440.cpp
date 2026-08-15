// Link: https://leetcode.com/problems/create-components-with-same-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> nums;
    int target;
    bool failed;

    int dfs(int u, int parent) {
        int sum = nums[u];
        for (int v : adj[u]) {
            if (v == parent) continue;
            int childSum = dfs(v, u);
            if (failed) return 0;
            sum += childSum;
        }
        if (sum > target) { failed = true; return 0; }
        if (sum == target) return 0;
        return sum;
    }

public:
    int componentValue(vector<int>& nums_, vector<vector<int>>& edges) {
        nums = nums_;
        int n = nums.size();
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        int maxVal = *max_element(nums.begin(), nums.end());

        for (int parts = n; parts >= 1; parts--) {
            if (total % parts != 0) continue;
            target = total / parts;
            if (target < maxVal) continue;
            failed = false;
            int rootRemainder = dfs(0, -1);
            if (!failed && rootRemainder == 0) return parts - 1;
        }
        return 0;
    }
};

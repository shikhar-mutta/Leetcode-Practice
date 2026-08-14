// Link: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int x = -1;
        for (int i = 0; i < n; i++) if (nums[i] == 1) { x = i; break; }
        if (x == -1) return ans;

        vector<vector<int>> children(n);
        for (int i = 0; i < n; i++) if (parents[i] != -1) children[parents[i]].push_back(i);

        unordered_set<int> seen;
        int mex = 1;
        int prev = -1;
        int cur = x;
        vector<int> stk;
        while (cur != -1) {
            stk.push_back(cur);
            while (!stk.empty()) {
                int u = stk.back(); stk.pop_back();
                seen.insert(nums[u]);
                for (int v : children[u]) if (v != prev) stk.push_back(v);
            }
            while (seen.count(mex)) mex++;
            ans[cur] = mex;
            prev = cur;
            cur = parents[cur];
        }
        return ans;
    }
};

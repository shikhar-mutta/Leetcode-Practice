// Link: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: any subtree not containing the node whose value is 1 has answer
// 1 trivially. Otherwise, walk from that node up to the root; at each step
// mark all values in the current subtree as seen (skipping the child branch
// already marked in the previous step, so total marking work across the
// whole walk is O(n)), then advance a running mex pointer.
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int target = -1;
        for (int i = 0; i < n; i++) if (nums[i] == 1) { target = i; break; }
        if (target == -1) return ans;

        vector<vector<int>> children(n);
        for (int i = 0; i < n; i++) if (parents[i] != -1) children[parents[i]].push_back(i);

        vector<bool> seen(n + 2, false);
        function<void(int, int)> mark = [&](int node, int skipChild) {
            if (nums[node] <= n + 1) seen[nums[node]] = true;
            for (int c : children[node]) {
                if (c == skipChild) continue;
                mark(c, -1);
            }
        };

        int mex = 1;
        int cur = target, skip = -1;
        while (cur != -1) {
            mark(cur, skip);
            while (mex < (int)seen.size() && seen[mex]) mex++;
            ans[cur] = mex;
            skip = cur;
            cur = parents[cur];
        }
        return ans;
    }
};

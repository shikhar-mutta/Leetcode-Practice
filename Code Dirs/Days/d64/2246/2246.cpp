// Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: build children adjacency, DFS post-order. For each node return
// longest downward chain (of distinct adjacent chars) starting at it. While
// visiting children, track the top-two chain lengths among children whose
// char differs from the node's char, to update global answer as
// best1+best2+1.
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
        int ans = 1;
        function<int(int)> dfs = [&](int u) -> int {
            int best1 = 0, best2 = 0;
            for (int v : children[u]) {
                int len = dfs(v);
                if (s[v] == s[u]) continue;
                if (len > best1) { best2 = best1; best1 = len; }
                else if (len > best2) best2 = len;
            }
            ans = max(ans, best1 + best2 + 1);
            return best1 + 1;
        };
        dfs(0);
        return ans;
    }
};

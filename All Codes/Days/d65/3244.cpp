// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+Q) log N), SC: O(N)
// Approach: edges only get added (never removed), so once a shortcut u->v exists, every node
// strictly between them is never optimal to visit again — remove them from a "kept nodes" set.
// The answer after each query is simply (kept set size - 1), the length of the path that jumps
// through every kept node in order.
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> kept;
        for (int i = 0; i < n; i++) kept.insert(i);

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            auto it = kept.upper_bound(u);
            while (it != kept.end() && *it < v) it = kept.erase(it);
            ans.push_back((int)kept.size() - 1);
        }
        return ans;
    }
};

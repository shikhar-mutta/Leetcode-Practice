// Link: https://leetcode.com/problems/longest-special-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> prefDist(n + 1, 0);
        unordered_map<int,int> lastSeen;
        int left = 0;
        long long bestLen = -1;
        int bestNodes = 0;

        struct Frame { int node, parent, depth; long long dist; size_t ci; int oldLast; int oldLeft; };
        vector<Frame> st;
        st.push_back({0, -1, 0, 0, 0, -2, 0});

        // process entry for root manually inside loop via a flag
        vector<bool> entered(n, false);

        while (!st.empty()) {
            Frame& f = st.back();
            if (f.ci == 0 && !entered[f.node]) {
                entered[f.node] = true;
                prefDist[f.depth] = f.dist;
                int old_last = lastSeen.count(nums[f.node]) ? lastSeen[nums[f.node]] : -1;
                f.oldLast = old_last;
                f.oldLeft = left;
                if (old_last != -1 && old_last >= left) left = old_last + 1;
                lastSeen[nums[f.node]] = f.depth;

                long long length = prefDist[f.depth] - prefDist[left];
                int nodeCount = f.depth - left + 1;
                if (length > bestLen || (length == bestLen && nodeCount < bestNodes)) {
                    bestLen = length;
                    bestNodes = nodeCount;
                }
            }

            if (f.ci < adj[f.node].size()) {
                auto [child, w] = adj[f.node][f.ci];
                f.ci++;
                if (child == f.parent) continue;
                st.push_back({child, f.node, f.depth + 1, f.dist + w, 0, -2, 0});
            } else {
                // restore state on exit
                lastSeen[nums[f.node]] = f.oldLast;
                left = f.oldLeft;
                st.pop_back();
            }
        }

        return {(int)bestLen, bestNodes};
    }
};

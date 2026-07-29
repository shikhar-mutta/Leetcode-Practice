// Link: https://leetcode.com/problems/longest-special-path-ii/description/

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
        unordered_map<int,int> lastOcc;
        int left = 0;
        int dupDepth = -1;
        long long bestLen = -1;
        int bestNodes = 0;

        struct Frame { int node, parent, depth; long long dist; size_t ci;
                        int oldLastOcc; bool hadOldLastOcc; int oldLeft; int oldDup; };
        vector<Frame> st;
        st.push_back({0, -1, 0, 0, 0, -2, false, 0, -1});
        vector<bool> entered(n, false);

        while (!st.empty()) {
            Frame& f = st.back();
            if (f.ci == 0 && !entered[f.node]) {
                entered[f.node] = true;
                prefDist[f.depth] = f.dist;

                int v = nums[f.node];
                bool had = lastOcc.count(v) > 0;
                int oldVal = had ? lastOcc[v] : -1;
                f.oldLastOcc = oldVal;
                f.hadOldLastOcc = had;
                f.oldLeft = left;
                f.oldDup = dupDepth;

                int p = had ? oldVal : -1;
                if (p != -1 && p >= left) {
                    if (dupDepth != -1) {
                        left = max(left, dupDepth + 1);
                        dupDepth = -1;
                        if (p >= left) dupDepth = p;
                    } else {
                        dupDepth = p;
                    }
                }
                lastOcc[v] = f.depth;

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
                st.push_back({child, f.node, f.depth + 1, f.dist + w, 0, -2, false, 0, -1});
            } else {
                int v = nums[f.node];
                if (f.hadOldLastOcc) lastOcc[v] = f.oldLastOcc;
                else lastOcc.erase(v);
                left = f.oldLeft;
                dupDepth = f.oldDup;
                st.pop_back();
            }
        }

        return {(int)bestLen, bestNodes};
    }
};

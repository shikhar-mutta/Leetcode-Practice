// Link: https://leetcode.com/problems/sequence-reconstruction/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E)  SC: O(V+E)
// Approach: build a graph from consecutive pairs in each sequence, run
// Kahn's topological sort; reconstruction is unique iff at every step
// exactly one node has in-degree 0, and the resulting order equals nums
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> adj;
        unordered_map<int, int> indeg;
        for (int x : nums) indeg[x] = 0;

        for (auto& seq : sequences) {
            for (int i = 0; i + 1 < (int)seq.size(); i++) {
                if (adj[seq[i]].insert(seq[i+1]).second) indeg[seq[i+1]]++;
            }
        }

        queue<int> q;
        for (auto& [node, d] : indeg) if (d == 0) q.push(node);

        vector<int> order;
        while (!q.empty()) {
            if (q.size() > 1) return false;
            int cur = q.front(); q.pop();
            order.push_back(cur);
            for (int next : adj[cur]) {
                if (--indeg[next] == 0) q.push(next);
            }
        }

        return order == nums;
    }
};

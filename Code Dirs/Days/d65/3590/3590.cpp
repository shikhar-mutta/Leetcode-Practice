// Link: https://leetcode.com/problems/kth-smallest-path-xor-sum/description/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        int n = vals.size();
        vector<vector<int>> children(n);
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (par[i] == -1) root = i;
            else children[par[i]].push_back(i);
        }

        vector<int> xorSum(n, 0);
        {
            vector<int> order;
            queue<int> q;
            q.push(root);
            xorSum[root] = vals[root];
            vector<bool> vis(n, false);
            vis[root] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int c : children[u]) {
                    if (!vis[c]) {
                        vis[c] = true;
                        xorSum[c] = xorSum[u] ^ vals[c];
                        q.push(c);
                    }
                }
            }
        }

        vector<vector<pair<int,int>>> queriesAt(n);
        int qn = queries.size();
        for (int i = 0; i < qn; i++) queriesAt[queries[i][0]].push_back({queries[i][1], i});

        vector<int> ans(qn, -1);
        vector<ordered_set*> sets(n, nullptr);

        // iterative post-order DFS
        vector<int> stk;
        vector<int> childPtr(n, 0);
        stk.push_back(root);
        vector<bool> entered(n, false);

        while (!stk.empty()) {
            int u = stk.back();
            if (!entered[u]) {
                entered[u] = true;
                sets[u] = new ordered_set();
                sets[u]->insert(xorSum[u]);
            }
            if (childPtr[u] < (int)children[u].size()) {
                int c = children[u][childPtr[u]++];
                stk.push_back(c);
            } else {
                for (int c : children[u]) {
                    if (sets[c]->size() > sets[u]->size()) swap(sets[u], sets[c]);
                    for (int v : *sets[c]) sets[u]->insert(v);
                    delete sets[c];
                    sets[c] = nullptr;
                }
                for (auto& [k, idx] : queriesAt[u]) {
                    if (k <= (int)sets[u]->size()) {
                        ans[idx] = *sets[u]->find_by_order(k - 1);
                    }
                }
                stk.pop_back();
            }
        }

        delete sets[root];
        return ans;
    }
};

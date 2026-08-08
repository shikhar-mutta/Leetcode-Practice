// Link: https://leetcode.com/problems/maximum-genetic-difference-query/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        int child[2] = {-1, -1};
        int count = 0;
    };
    vector<TrieNode> trie;

    int newNode() {
        trie.push_back(TrieNode());
        return trie.size() - 1;
    }

    void insert(int num, int delta) {
        int node = 0;
        for (int b = 17; b >= 0; b--) {
            int bit = (num >> b) & 1;
            if (trie[node].child[bit] == -1) trie[node].child[bit] = newNode();
            node = trie[node].child[bit];
            trie[node].count += delta;
        }
    }

    int query(int num) {
        int node = 0;
        int res = 0;
        for (int b = 17; b >= 0; b--) {
            int bit = (num >> b) & 1;
            int want = 1 - bit;
            if (trie[node].child[want] != -1 && trie[trie[node].child[want]].count > 0) {
                res |= (1 << b);
                node = trie[node].child[want];
            } else {
                node = trie[node].child[bit];
            }
        }
        return res;
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        vector<vector<int>> children(n);
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else children[parents[i]].push_back(i);
        }

        vector<vector<pair<int,int>>> nodeQueries(n);
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            nodeQueries[queries[i][0]].push_back({queries[i][1], i});
        }

        newNode(); // root of trie
        function<void(int)> dfs = [&](int u) {
            insert(u, 1);
            for (auto& [val, idx] : nodeQueries[u]) {
                ans[idx] = query(val);
            }
            for (int v : children[u]) dfs(v);
            insert(u, -1);
        };
        dfs(root);

        return ans;
    }
};

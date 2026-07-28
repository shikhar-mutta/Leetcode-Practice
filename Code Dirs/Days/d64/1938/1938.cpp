// Link: https://leetcode.com/problems/maximum-genetic-difference-query/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n + q) * 18)  SC: O((n + q) * 18)
// Approach: DFS the tree with a binary trie of ancestor values (insert on
// entry, remove on exit), answering each node's queries at the moment it's
// visited by greedily walking the trie to maximize XOR with the query value.
class Solution {
    static const int BITS = 18;
    struct Node { int cnt = 0; int ch[2] = {-1, -1}; };
    vector<Node> trie;

    void insert(int x) {
        int cur = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (trie[cur].ch[bit] == -1) {
                trie[cur].ch[bit] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].ch[bit];
            trie[cur].cnt++;
        }
    }
    void remove(int x) {
        int cur = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            cur = trie[cur].ch[bit];
            trie[cur].cnt--;
        }
    }
    int query(int x) {
        int cur = 0, res = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur].ch[want] != -1 && trie[trie[cur].ch[want]].cnt > 0) {
                res |= (1 << b);
                cur = trie[cur].ch[want];
            } else {
                cur = trie[cur].ch[bit];
            }
        }
        return res;
    }
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        vector<vector<int>> children(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else children[parents[i]].push_back(i);
        }
        vector<vector<pair<int,int>>> qAtNode(n); // (queryVal, queryIdx)
        int q = queries.size();
        for (int i = 0; i < q; i++) qAtNode[queries[i][0]].push_back({queries[i][1], i});

        vector<int> ans(q, 0);
        trie.push_back(Node());

        function<void(int)> dfs = [&](int u) {
            insert(u);
            for (auto& [val, idx] : qAtNode[u]) ans[idx] = query(val);
            for (int c : children[u]) dfs(c);
            remove(u);
        };
        dfs(root);
        return ans;
    }
};

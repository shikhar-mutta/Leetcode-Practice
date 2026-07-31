// Link: https://leetcode.com/problems/maximum-genetic-difference-query/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: We can use a trie data structure to store the binary representation of the numbers. We can then perform a depth-first search (DFS) on the tree and for each query, we can find the maximum genetic difference by traversing the trie and finding the number that has the maximum XOR with the given number. We can then return the result for each query.
class Trie
{
public:
    vector<array<int, 2>> trie;
    vector<int> cnt, nm;
    Trie()
    {
        trie.clear();
        trie.push_back({-1, -1});
        cnt.clear();
        cnt.push_back(-1);
        nm.clear();
        nm.push_back(0);
    }
    void insert(int s)
    {
        int x = 0;
        ++nm[0];
        for (int i = 17; i >= 0; --i)
        {
            int p = (s & (1 << i)) >> i;
            if (trie[x][p] == -1)
            {
                trie[x][p] = trie.size();
                trie.push_back({-1, -1});
                cnt.push_back(-1);
                nm.push_back(0);
            }
            ++nm[trie[x][p]];
            x = trie[x][p];
        }
        cnt[x] = s;
    }
    void del(int s)
    {
        int x = 0;
        --nm[0];
        for (int i = 17; i >= 0; --i)
        {
            int p = (s & (1 << i)) >> i;
            --nm[trie[x][p]];
            x = trie[x][p];
        }
        cnt[x] = -1;
    }
    int find(int s)
    {
        int x = 0;
        for (int i = 17; i >= 0; --i)
        {
            int c = (s & (1 << i)) >> i;
            int p = (~c) & 1;
            if (trie[x][p] == -1 || nm[trie[x][p]] == 0)
            {
                p = c;
            }
            x = trie[x][p];
        }
        return cnt[x] ^ s;
    }
};
class Solution
{
    void dfs(int x, vector<vector<int>> &kraw,
             vector<vector<pair<int, int>>> &qr, vector<int> &ans, Trie &tree)
    {
        tree.insert(x);
        for (auto &v : qr[x])
        {
            ans[v.second] = tree.find(v.first);
        }
        for (auto &v : kraw[x])
        {
            dfs(v, kraw, qr, ans, tree);
        }
        tree.del(x);
    }

public:
    vector<int> maxGeneticDifference(vector<int> &parents,
                                     vector<vector<int>> &queries)
    {
        int n = parents.size();
        int m = queries.size();
        Trie tree;
        vector<vector<int>> kraw(n);
        vector<vector<pair<int, int>>> qr(n);
        int root = 0;
        for (int i = 0; i < n; ++i)
        {
            if (parents[i] == -1)
            {
                root = i;
            }
            else
            {
                kraw[parents[i]].push_back(i);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            qr[queries[i][0]].push_back({queries[i][1], i});
        }
        vector<int> ans(m);
        dfs(root, kraw, qr, ans, tree);
        return ans;
    }
};
// Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logN) SC: O(NlogN)
// Approach: We can use binary lifting technique to solve this problem. We can create a table where table[i][j] represents the 2^i-th ancestor of node j. We can fill this table using dynamic programming. Finally, we can use this table to find the k-th ancestor of a node in O(logN) time.
class TreeAncestor
{
public:
    vector<int> parent;
    int n;
    vector<vector<int>> table;
    TreeAncestor(int n, vector<int> &parent)
    {
        this->n = n;
        this->parent = parent;
        binaryLiftingTable();
    }
    void binaryLiftingTable()
    {
        int maxlog = log2(n) + 1;
        table.assign(maxlog, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            table[0][i] = parent[i];
        for (int j = 1; j < maxlog; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (table[j - 1][i] != -1)
                    table[j][i] = table[j - 1][table[j - 1][i]];
            }
        }
    }
    int getKthAncestor(int node, int k)
    {
        int dist = k;
        int maxlog = log2(n) + 1;
        for (int i = maxlog - 1; i >= 0; i--)
        {
            if (dist & (1 << i))
                node = table[i][node];
            if (node == -1)
                return -1;
        }
        return node;
    }
};

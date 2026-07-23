// Link: https://leetcode.com/problems/possible-bipartition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m * α(n)), SC: O(n)
// Approach:
//  1. Initialize a union-find data structure to keep track of connected components.
//  2. Create an array to store the enemy of each person.
//  3. Iterate through the dislikes array and for each pair of people (a, b):
//     a. If a and b are in the same connected component, return false (not bipartite).
//     b. If a has no enemy, set b as a's enemy.
//     c. If a has an enemy, merge b with a's enemy in the union-find structure.
//     d. Repeat the same for b and a.
//  4. If all pairs are processed without conflicts, return true (bipartite).
//  5. The union-find structure helps efficiently manage the connected components and check for conflicts.
class Solution
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool merge(int i, int j)
    {
        int li = find(i);
        int lj = find(j);
        if (li == lj)
            return false;
        if (rank[li] > rank[lj])
        {
            parent[lj] = li;
        }
        else if (rank[lj] > rank[li])
        {
            parent[li] = lj;
        }
        else
        {
            parent[lj] = li;
            rank[li]++;
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        init(n + 1);
        vector<int> enemy(n + 1, 0);
        for (const vector<int> &d : dislikes)
        {
            if (find(d[0]) == find(d[1]))
                return false;
            if (enemy[d[0]] == 0)
            {
                enemy[d[0]] = d[1];
            }
            else
            {
                merge(d[1], enemy[d[0]]);
            }
            if (enemy[d[1]] == 0)
            {
                enemy[d[1]] = d[0];
            }
            else
            {
                merge(d[0], enemy[d[1]]);
            }
        }
        return true;
    }
};
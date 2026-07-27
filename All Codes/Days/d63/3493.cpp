// Link: https://leetcode.com/problems/properties-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * maxSetSize) SC: O(n)
//  Approach: union-find. For each pair (i,j), connect them if the size of
//  the intersection of their property sets is >= k. Answer is the number
//  of resulting components.
class Solution
{
public:
    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        int n = properties.size();
        vector<int> parent(n, 0);
        vector<int> size(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<bitset<101>> qw(n);

        for (int i = 0; i < n; i++)
        {
            for (auto b : properties[i])
            {
                qw[i].set(b);
            }
        }

        int cmp = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((qw[i] & qw[j]).count() >= k)
                {
                    if (unionF(i, j, parent, size))
                        cmp--;
                }
            }
        }

        return cmp;
    }

    int find_dsu(int key, vector<int> &parent)
    {
        if (parent[key] == key)
            return key;
        return parent[key] = find_dsu(parent[key], parent);
    }
    bool unionF(int k1, int k2, vector<int> &parent, vector<int> &size)
    {
        k1 = find_dsu(k1, parent);
        k2 = find_dsu(k2, parent);
        if (k1 == k2)
            return false;

        if (size[k1] < size[k2])
        {
            int temp = k2;
            k2 = k1;
            k1 = temp;
        }

        parent[k2] = k1;
        size[k1] += size[k2];
        return true;
    }
};
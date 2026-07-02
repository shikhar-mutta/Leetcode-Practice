// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * α(n)) where n is the number of stones and α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical input sizes. The union-find operations (find and union) are nearly constant time due to path compression and union by rank optimizations.
    // SC: O(n) for the parent array and the rowFirst and colFirst maps,
    //  Approach: Union-Find (Disjoint Set Union)
    int removeStones(vector<vector<int>> &stones)
    {
        int m = stones.size();
        vector<int> parent(m);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x)
        {
            while (parent[x] != x)
                x = parent[x] = parent[parent[x]];
            return x;
        };

        // Union stones that share a row or column, via the first stone
        // seen in each row / column.
        unordered_map<int, int> rowFirst, colFirst;
        int components = m;
        auto join = [&](int a, int b)
        {
            int ra = find(a), rb = find(b);
            if (ra != rb)
            {
                parent[ra] = rb;
                components--;
            }
        };
        for (int i = 0; i < m; i++)
        {
            int r = stones[i][0], c = stones[i][1];
            if (rowFirst.count(r))
                join(i, rowFirst[r]);
            else
                rowFirst[r] = i;
            if (colFirst.count(c))
                join(i, colFirst[c]);
            else
                colFirst[c] = i;
        }

        // Each component collapses to one remaining stone.
        return m - components;
    }
};

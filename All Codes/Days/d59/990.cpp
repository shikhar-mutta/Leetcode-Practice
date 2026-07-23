// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: Union-Find (Disjoint Set Union)
class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (auto &eq : equations)
        {
            if (eq[1] == '=')
            {
                int a = eq[0] - 'a', b = eq[3] - 'a';
                parent[find(a)] = find(b);
            }
        }

        for (auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                int a = eq[0] - 'a', b = eq[3] - 'a';
                if (find(a) == find(b))
                    return false;
            }
        }
        return true;
    }
};

// Link: https://leetcode.com/problems/cracking-the-safe/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k^n)  SC: O(k^n)
//  Approach: build a de Bruijn sequence via Hierholzer's algorithm on the
//  graph where nodes are (n-1)-length strings over digits 0..k-1 and an
//  edge node->node[1:]+d exists for each digit d (representing the
//  n-length password node+d). A post-order DFS from the all-zero node,
//  appending the edge digit after recursing, produces the Eulerian
//  circuit in reverse; reversing it and prepending the start node gives
//  the shortest string containing every possible password as a substring.
class Solution
{
public:
    bool seen[10001];
    string res;
    int K, MOD;

    void dfs(int u)
    {
        for (int i = 0; i < K; ++i)
        {
            int e = u * K + i;
            if (!seen[e])
            {
                seen[e] = true;
                dfs((u * K + i) % MOD);
                res.push_back('0' + i);
            }
        }
    }

    string crackSafe(int n, int k)
    {
        memset(seen, 0, sizeof(seen));
        int total = 1;
        for (int i = 0; i < n; ++i)
            total *= k;
        K = k;
        MOD = total / k;

        res.reserve(total + n - 1);
        dfs(0);
        res.append(n - 1, '0');
        return res;
    }
};
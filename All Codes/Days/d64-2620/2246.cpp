// Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach: We can use a depth-first search (DFS) approach to solve this problem. We can start from the root node and traverse the tree using DFS. For each node, we can keep track of the longest path that can be formed by its children. If the character of the current node is different from its child, we can update the longest path accordingly. Finally, we return the maximum length of the path found during the traversal.
class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        const int n{static_cast<int>(parent.size())};
        static int from[100001]{}, to[99999]{};
        memset(from, 0, sizeof(int) * n);
        for (int i{1}; i < n; ++i)
            ++from[parent[i]];
        exclusive_scan(from, from + n, from, 0);
        for (int i{1}; i < n; ++i)
            to[from[parent[i]]++] = i;
        for (int i{n}; i > 0; --i)
            from[i] = from[i - 1];
        from[0] = 0;
        int res{0};
        auto dfs{[&](this auto &&dfs, int i) -> int
                 {
                     int ret{1};
                     const char c{s[i]};
                     for (const int j :
                          span<const int>{to + from[i], to + from[i + 1]})
                     {
                         const int add{dfs(j)};
                         const char d{s[j]};
                         if (c != d)
                         {
                             res = max(res, ret + add);
                             ret = max(ret, add + 1);
                         }
                     }
                     res = max(res, ret);
                     return ret;
                 }};
        dfs(0);
        return res;
    }
};

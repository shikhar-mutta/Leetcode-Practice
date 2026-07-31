// Link: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Use DFS to traverse the tree and keep track of the smallest missing genetic value in each subtree. Use a bitset to mark the genetic values that have been seen in the subtree.
class Solution
{
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents,
                                            vector<int> &nums)
    {
        const int n{static_cast<int>(parents.size())};
        int root{-1};
        for (int i{0}; i < n; ++i)
        {
            if (nums[i] == 1)
            {
                root = i;
                break;
            }
        }
        if (root == -1)
            return vector<int>(n, 1);
        static int from[100001]{}, to[99999]{};
        memset(from, 0, sizeof(int) * n);
        for (int i{1}; i < n; ++i)
            ++from[parents[i]];
        exclusive_scan(from, from + n, from, 0);
        for (int i{1}; i < n; ++i)
            to[from[parents[i]]++] = i;
        from[n] = from[n - 1];
        for (int i{n - 1}; i > 0; --i)
            from[i] = from[i - 1];
        from[0] = 0;
        vector<int> res(n, 1);
        static bitset<100002> vis{};
        vis.reset();
        auto dfs{[&](this auto &&dfs, int i) -> void
                 {
                     vis[nums[i]] = true;
                     for (int idx{from[i]}; idx < from[i + 1]; ++idx)
                         dfs(to[idx]);
                 }};
        int ptr{1};
        for (int i{root}, last{-1}; i >= 0; last = i, i = parents[i])
        {
            vis[nums[i]] = true;
            for (int idx{from[i]}; idx < from[i + 1]; ++idx)
            {
                if (to[idx] != last)
                    dfs(to[idx]);
            }
            while (vis[ptr])
                ++ptr;
            res[i] = ptr;
        }
        return res;
    }
};

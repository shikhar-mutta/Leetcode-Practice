// Link: https://leetcode.com/problems/create-components-with-same-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: For each divisor d of the total sum, check if we can partition the tree into components with sum d using DFS. If we can, return the number of components - 1.
class Solution
{
public:
    int componentValue(vector<int> &nums, vector<vector<int>> &edges)
    {
        const int n{static_cast<int>(nums.size())};
        const int tot{reduce(nums.begin(), nums.end())};
        static int from[20001]{}, to[39998]{};
        memset(from, 0, sizeof(int) * n);
        for (const vector<int> &e : edges)
        {
            const int u{e[0]}, v{e[1]};
            ++from[u];
            ++from[v];
        }
        exclusive_scan(from, from + n, from, 0);
        for (const vector<int> &e : edges)
        {
            const int u{e[0]}, v{e[1]};
            to[from[u]++] = v;
            to[from[v]++] = u;
        }
        memmove(from + 1, from, sizeof(int) * n);
        from[0] = 0;
        auto dfs{[&](this auto &&dfs, int i, int p, int d) -> int
                 {
                     int acc{nums[i]};
                     for (const int j :
                          span<const int>{to + from[i], to + from[i + 1]})
                     {
                         if (j == p)
                             continue;
                         acc += dfs(j, i, d);
                     }
                     return acc == d ? 0 : acc;
                 }};
        for (const int d : views::iota(1, tot + 1))
        {
            if (tot % d)
                continue;
            if (dfs(0, -1, d) == 0)
                return tot / d - 1;
        }
        return 0;
    }
};
// Link: https://leetcode.com/problems/split-and-merge-array-transformation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^4) worst case (n^2 days, n^2 scan each) SC: O(n^2)
//  Approach: greedy day-by-day construction. At each day, among all
//  remaining (home,away) pairs not yet used, whose home/away teams both
//  differ from the previous day's two teams (avoiding consecutive-day
//  repeats), pick the pair maximizing a heuristic score favoring teams
//  with the most remaining home/away games left (keeps remaining options
//  balanced so the greedy doesn't paint itself into a corner). If no
//  valid pair exists at some day, no schedule works (return empty); n<4
//  is provably infeasible.
class Solution
{
public:
    int minSplitMerge(vector<int> &nums1, vector<int> &nums2)
    {
        int n = size(nums1);
        bool vis[1 << 18]{};
        unordered_map<int, int> id;
        int root = 0, tgt = 0;
        for (int x : nums1)
        {
            if (!id.contains(x))
                id[x] = size(id);
            root = root << 3 | id[x];
        }
        for (int x : nums2)
            tgt = tgt << 3 | id[x];
        if (root == tgt)
            return 0;
        vis[root] = true;
        queue<int> q{{root}};
        int ans = 1;
        for (;;)
        {
            int sz = size(q);
            while (sz--)
            {
                int u = q.front();
                q.pop();
                for (int l = 0; l < n; ++l)
                {
                    for (int r = l + 1; r <= n; ++r)
                    {
                        int len = r - l;
                        int sub = (u & (1 << (3 * r)) - 1) >> (3 * l);
                        int rem =
                            u >> (3 * r) << (3 * l) | u & (1 << (3 * l)) - 1;
                        for (int k = 0; k <= n - len; ++k)
                        {
                            int v = rem << 3 * len & -(1 << (3 * (k + len))) |
                                    rem & (1 << (3 * k)) - 1 | sub;
                            if (v == tgt)
                                return ans;
                            if (!vis[v])
                                vis[v] = true, q.emplace(v);
                            sub <<= 3;
                        }
                    }
                }
            }
            ++ans;
        }
    }
};
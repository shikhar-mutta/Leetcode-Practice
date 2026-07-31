// Link: https://leetcode.com/problems/contain-virus/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R * C * (R * C))  SC: O(R * C)
//  Approach: DFS. For each region, count the number of walls needed to quarantine it and the number of uninfected cells it can infect. Quarantine the region that can infect the most uninfected cells. Then, spread the virus from the other regions. Repeat until no more virus can be spread. Return the total number of walls needed to quarantine all regions.

static int mp[2652], *zp[2652], zc[2652], step, mk;

// Force inline + restrict + branch prediction hints
[[gnu::always_inline]]
static inline int dfs(int *__restrict__ p)
{
    *p = 2;
    int res = 0;

    // Unrolled loop: eliminates initializer_list iterator overhead
    {
        int *nb = p - step, v = *nb;
        if (__builtin_expect(v != mk && v <= 1, 1))
        {
            if (v <= 0)
                *nb = mk, ++res;
            else
                res += dfs(nb);
        }
    }
    {
        int *nb = p - 1, v = *nb;
        if (__builtin_expect(v != mk && v <= 1, 1))
        {
            if (v <= 0)
                *nb = mk, ++res;
            else
                res += dfs(nb);
        }
    }
    {
        int *nb = p + 1, v = *nb;
        if (__builtin_expect(v != mk && v <= 1, 1))
        {
            if (v <= 0)
                *nb = mk, ++res;
            else
                res += dfs(nb);
        }
    }
    {
        int *nb = p + step, v = *nb;
        if (__builtin_expect(v != mk && v <= 1, 1))
        {
            if (v <= 0)
                *nb = mk, ++res;
            else
                res += dfs(nb);
        }
    }
    return res;
}

[[gnu::always_inline]]
static inline int dfs2(int *__restrict__ p)
{
    *p = 1000;
    int res = 0;
    {
        int *nb = p - step, v = *nb;
        if (v == 2)
            res += dfs2(nb);
        else if (__builtin_expect(v <= 0, 1))
            ++res, *nb = 0;
    }
    {
        int *nb = p - 1, v = *nb;
        if (v == 2)
            res += dfs2(nb);
        else if (__builtin_expect(v <= 0, 1))
            ++res, *nb = 0;
    }
    {
        int *nb = p + 1, v = *nb;
        if (v == 2)
            res += dfs2(nb);
        else if (__builtin_expect(v <= 0, 1))
            ++res, *nb = 0;
    }
    {
        int *nb = p + step, v = *nb;
        if (v == 2)
            res += dfs2(nb);
        else if (__builtin_expect(v <= 0, 1))
            ++res, *nb = 0;
    }
    return res;
}

[[gnu::always_inline]]
static inline void dfs3(int *__restrict__ p)
{
    *p = 1;
    {
        int *nb = p - step, v = *nb;
        if (v == 2)
            dfs3(nb);
        else if (__builtin_expect(v <= 0, 1))
            *nb = 1;
    }
    {
        int *nb = p - 1, v = *nb;
        if (v == 2)
            dfs3(nb);
        else if (__builtin_expect(v <= 0, 1))
            *nb = 1;
    }
    {
        int *nb = p + 1, v = *nb;
        if (v == 2)
            dfs3(nb);
        else if (__builtin_expect(v <= 0, 1))
            *nb = 1;
    }
    {
        int *nb = p + step, v = *nb;
        if (v == 2)
            dfs3(nb);
        else if (__builtin_expect(v <= 0, 1))
            *nb = 1;
    }
}

class Solution
{
public:
    int containVirus(vector<vector<int>> &g)
    {
        int R = g.size(), C = g[0].size();
        step = C + 1;
        mk = 0;
        int *p = mp + step;

        for (int i = 0; i < step; ++i)
            mp[i] = 1000;
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
                *p++ = g[r][c];
            *p++ = 1000;
        }
        for (int i = 0; i < step; ++i)
            *p++ = 1000;

        int *lo = mp + step, *hi = lo + step * R, res = 0;
        while (1)
        {
            int nb = 0;
            for (int *p = lo; p != hi; ++p)
                if (*p == 1)
                    zp[nb] = p, --mk, zc[nb++] = dfs(p);
            if (!nb)
                break;
            int best = 0;
            for (int i = 1; i < nb; ++i)
                if (zc[i] > zc[best])
                    best = i;
            if (!zc[best])
                break;
            res += dfs2(zp[best]);
            for (int *p = lo; p != hi; ++p)
                if (*p == 2)
                    dfs3(p);
        }
        return res;
    }
};
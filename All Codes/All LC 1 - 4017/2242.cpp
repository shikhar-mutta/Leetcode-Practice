// Link: https://leetcode.com/problems/maximum-score-of-a-node-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(E) SC: O(V)
    // Approach:
    //  1. For each node, keep track of the top 3 neighbors with the highest scores.
    //  2. For each edge (b, c), consider the top 3 neighbors of b and c to form sequences (a, b, c, d) where    a is a neighbor of b and d is a neighbor of c.
    //  3. Calculate the score for each valid sequence and keep track of the maximum score found.

    int maximumScore(vector<int> &scores, vector<vector<int>> &edges)
    {
        const int n = scores.size(), E = edges.size();
        const int *__restrict__ sc = scores.data();

        // top3[i*3+0..2] = top-3 neighbor indices for node i (sorted by score
        // desc) cnt[i] = number of valid entries in top3[i] (0..3)
        vector<uint16_t> top3(n * 3, 0xFFFF);
        vector<uint8_t> cnt(n, 0);
        // Flat edge array: [b0,c0,b1,c1,...] — contiguous, cache-friendly
        vector<int> flat(2 * E);

        uint16_t *__restrict__ tp = top3.data();
        uint8_t *__restrict__ cp = cnt.data();
        int *__restrict__ fp = flat.data();

        // Build phase: single pass over edges
        for (int i = 0; i < E; i++)
        {
            const int u = edges[i][0], v = edges[i][1];
            fp[2 * i] = u;
            fp[2 * i + 1] = v;

            // Insert v into u's top-3
            {
                const int s = sc[v];
                int c = cp[u];
                uint16_t *__restrict__ t = tp + u * 3;
                if (c == 0)
                {
                    t[0] = (uint16_t)v;
                    cp[u] = 1;
                }
                else if (c == 1)
                {
                    if (s > sc[t[0]])
                    {
                        t[1] = t[0];
                        t[0] = (uint16_t)v;
                    }
                    else
                        t[1] = (uint16_t)v;
                    cp[u] = 2;
                }
                else if (c == 2)
                {
                    if (s > sc[t[0]])
                    {
                        t[2] = t[1];
                        t[1] = t[0];
                        t[0] = (uint16_t)v;
                    }
                    else if (s > sc[t[1]])
                    {
                        t[2] = t[1];
                        t[1] = (uint16_t)v;
                    }
                    else
                        t[2] = (uint16_t)v;
                    cp[u] = 3;
                }
                else if (s > sc[t[2]])
                {
                    if (s > sc[t[0]])
                    {
                        t[2] = t[1];
                        t[1] = t[0];
                        t[0] = (uint16_t)v;
                    }
                    else if (s > sc[t[1]])
                    {
                        t[2] = t[1];
                        t[1] = (uint16_t)v;
                    }
                    else
                        t[2] = (uint16_t)v;
                }
            }
            // Insert u into v's top-3
            {
                const int s = sc[u];
                int c = cp[v];
                uint16_t *__restrict__ t = tp + v * 3;
                if (c == 0)
                {
                    t[0] = (uint16_t)u;
                    cp[v] = 1;
                }
                else if (c == 1)
                {
                    if (s > sc[t[0]])
                    {
                        t[1] = t[0];
                        t[0] = (uint16_t)u;
                    }
                    else
                        t[1] = (uint16_t)u;
                    cp[v] = 2;
                }
                else if (c == 2)
                {
                    if (s > sc[t[0]])
                    {
                        t[2] = t[1];
                        t[1] = t[0];
                        t[0] = (uint16_t)u;
                    }
                    else if (s > sc[t[1]])
                    {
                        t[2] = t[1];
                        t[1] = (uint16_t)u;
                    }
                    else
                        t[2] = (uint16_t)u;
                    cp[v] = 3;
                }
                else if (s > sc[t[2]])
                {
                    if (s > sc[t[0]])
                    {
                        t[2] = t[1];
                        t[1] = t[0];
                        t[0] = (uint16_t)u;
                    }
                    else if (s > sc[t[1]])
                    {
                        t[2] = t[1];
                        t[1] = (uint16_t)u;
                    }
                    else
                        t[2] = (uint16_t)u;
                }
            }
        }

        // Evaluation phase: single pass over flat edges
        int ans = -1;
        for (int i = 0; i < E; i++)
        {
            const int b = fp[2 * i], c = fp[2 * i + 1];
            const int cb = cp[b], cc = cp[c];
            if (!cb || !cc)
                continue;

            const uint16_t *__restrict__ nb = tp + b * 3;
            const uint16_t *__restrict__ nc = tp + c * 3;
            const int bc = sc[b] + sc[c];
            const int bd = sc[nc[0]];

            // Edge-level prune: upper bound can't beat current best
            if (bc + sc[nb[0]] + bd <= ans)
                continue;

            for (int ai = 0; ai < cb; ai++)
            {
                const int a = nb[ai];
                if (a == c)
                    continue;
                const int base = sc[a] + bc;
                // a-level prune: future a's have lower scores
                if (base + bd <= ans)
                    break;

                // d-loop unrolled (at most 3 candidates)
                {
                    int d = nc[0];
                    if (d != b && d != a)
                    {
                        int t = base + sc[d];
                        if (t > ans)
                            ans = t;
                        continue;
                    }
                }
                if (cc < 2)
                    continue;
                {
                    int d = nc[1];
                    if (d != b && d != a)
                    {
                        int t = base + sc[d];
                        if (t > ans)
                            ans = t;
                        continue;
                    }
                }
                if (cc < 3)
                    continue;
                {
                    int d = nc[2];
                    if (d != b && d != a)
                    {
                        int t = base + sc[d];
                        if (t > ans)
                            ans = t;
                    }
                }
            }
        }
        return ans;
    }
};
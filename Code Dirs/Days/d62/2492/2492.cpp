// Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m * alpha(n)) — union-find with path halving over m roads
// SC: O(n)
// Approach: any path from 1 to n can freely reuse edges, so the reachable
// set from 1 is exactly its connected component, and the minimum score is
// just the minimum edge weight anywhere inside that component. Union-find
// merges each edge's endpoints (always attaching the larger root under
// the smaller, so node 1 — the smallest label — stays the root of its
// component) while tracking the running minimum edge weight per
// component; the answer is that minimum for the component rooted at 1.
#pragma GCC optimize(                                                          \
    "O3,unroll-loops,fast-math,no-stack-protector,strict-aliasing,omit-frame-pointer,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static uint32_t p[100005];
static uint32_t min_w[100005];

class Solution {
public:
    [[clang::always_inline]] static uint32_t find(uint32_t i) {
        while (i != p[i]) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        [[assume(n >= 2 && n <= 100000)]];

#pragma clang loop vectorize(enable) interleave(enable)
        for (uint32_t i = 1; i <= static_cast<uint32_t>(n); ++i) {
            p[i] = i;
            min_w[i] = 10005;
        }

        const int m = roads.size();

        for (int i = 0; i < m; ++i) {
            if (i + 2 < m)
                __builtin_prefetch(&roads[i + 2], 0, 1);
            if (i + 1 < m)
                __builtin_prefetch(roads[i + 1].data(), 0, 3);

            const int* __restrict edge = roads[i].data();
            [[assume(edge != nullptr)]];

            uint32_t u = edge[0];
            uint32_t v = edge[1];
            uint32_t w = edge[2];

            uint32_t ru = find(u);
            uint32_t rv = find(v);

            if (ru == rv) {
                min_w[ru] = min(min_w[ru], w);
                continue;
            }

            if (ru > rv) {
                p[ru] = rv;
                min_w[rv] = min({min_w[rv], min_w[ru], w});
            } else {
                p[rv] = ru;
                min_w[ru] = min({min_w[ru], min_w[rv], w});
            }
        }

        return min_w[1];
    }
};

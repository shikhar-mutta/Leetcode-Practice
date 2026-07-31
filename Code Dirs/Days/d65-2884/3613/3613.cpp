// Link: https://leetcode.com/problems/minimize-maximum-component-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        auto feasible = [&](int X) -> bool {
            vector<int> par(n);
            iota(par.begin(), par.end(), 0);
            function<int(int)> find = [&](int x) { return par[x]==x ? x : par[x]=find(par[x]); };
            int comps = n;
            for (auto& e : edges) {
                if (e[2] <= X) {
                    int a = find(e[0]), b = find(e[1]);
                    if (a != b) { par[a] = b; comps--; }
                }
            }
            return comps <= k;
        };

        int lo = 0, hi = 0;
        for (auto& e : edges) hi = max(hi, e[2]);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};

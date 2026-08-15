// Link: https://leetcode.com/problems/minimum-time-for-k-connected-components/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int maxT = 0;
        for (auto& e : edges) maxT = max(maxT, e[2]);

        auto feasible = [&](int t) -> bool {
            vector<int> par(n);
            iota(par.begin(), par.end(), 0);
            function<int(int)> find = [&](int x) { return par[x]==x ? x : par[x]=find(par[x]); };
            int comps = n;
            for (auto& e : edges) {
                if (e[2] > t) {
                    int a = find(e[0]), b = find(e[1]);
                    if (a != b) { par[a] = b; comps--; }
                }
            }
            return comps >= k;
        };

        int lo = 0, hi = maxT;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};

// Link: https://leetcode.com/problems/number-of-good-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> parent, cnt;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        cnt.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);

        sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });

        long long ans = n;
        for (auto &e : edges) {
            int ru = find(e[0]), rv = find(e[1]);
            if (ru == rv) continue;
            if (vals[ru] > vals[rv]) {
                parent[rv] = ru;
            } else if (vals[rv] > vals[ru]) {
                parent[ru] = rv;
            } else {
                ans += (long long)cnt[ru] * cnt[rv];
                parent[rv] = ru;
                cnt[ru] += cnt[rv];
            }
        }
        return (int)ans;
    }
};

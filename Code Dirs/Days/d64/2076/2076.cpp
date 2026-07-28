// Link: https://leetcode.com/problems/process-restricted-friend-requests/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(requests * restrictions * alpha)  SC: O(n)
// Approach: Union-Find over friendships. For each request (u,v), tentatively
// check whether union(u,v) would place any restricted pair in the same
// component (by comparing find() of both restriction endpoints against
// find(u)/find(v)); if not, accept the request and union.
class Solution {
    vector<int> par;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) par[a] = b;
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        vector<bool> res;
        for (auto& r : requests) {
            int u = r[0], v = r[1];
            int ru = find(u), rv = find(v);
            bool ok = true;
            if (ru != rv) {
                for (auto& res_pair : restrictions) {
                    int a = find(res_pair[0]), b = find(res_pair[1]);
                    if ((a == ru && b == rv) || (a == rv && b == ru)) { ok = false; break; }
                }
            }
            if (ok) unite(u, v);
            res.push_back(ok);
        }
        return res;
    }
};

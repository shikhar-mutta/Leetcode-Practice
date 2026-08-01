// Link: https://leetcode.com/problems/block-placement-queries/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+q) log(n+q))  SC: O(n+q)
// Approach: coordinate-compress every obstacle position and query bound
// (plus 0). Segment tree over compressed indices; each node tracks the
// min/max active (obstacle) coordinate in its range and the max gap
// between consecutive active coordinates within that range. A type-1
// query activates a coordinate (point update + merge up). A type-2 query
// [x, sz] range-queries [0, x]; the answer is feasible iff the largest
// gap (including the boundary gaps 0->firstActive and lastActive->x, or
// the whole [0,x] span if nothing is active) is >= sz.
class Solution {
    struct Info { long long minA, maxA, maxGap; };
    vector<Info> tree;
    vector<long long> coords;
    int m;
    const long long INF = LLONG_MAX / 2;

    Info merge(const Info& l, const Info& r) {
        if (l.minA == INF) return r;
        if (r.minA == INF) return l;
        Info res;
        res.minA = l.minA;
        res.maxA = r.maxA;
        res.maxGap = max({l.maxGap, r.maxGap, r.minA - l.maxA});
        return res;
    }

    void update(int node, int lo, int hi, int pos, long long val) {
        if (lo == hi) { tree[node] = {val, val, 0}; return; }
        int mid = (lo + hi) / 2;
        if (pos <= mid) update(node*2, lo, mid, pos, val);
        else update(node*2+1, mid+1, hi, pos, val);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Info query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return {INF, -INF, 0};
        if (l <= lo && hi <= r) return tree[node];
        int mid = (lo + hi) / 2;
        return merge(query(node*2, lo, mid, l, r), query(node*2+1, mid+1, hi, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<long long> allCoords;
        allCoords.push_back(0);
        for (auto& q : queries) {
            if (q[0] == 1) allCoords.push_back(q[1]);
            else allCoords.push_back(q[1]);
        }
        sort(allCoords.begin(), allCoords.end());
        allCoords.erase(unique(allCoords.begin(), allCoords.end()), allCoords.end());
        coords = allCoords;
        m = coords.size();
        tree.assign(4 * m, {INF, -INF, 0});
        auto idx = [&](long long v) { return lower_bound(coords.begin(), coords.end(), v) - coords.begin(); };

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, m - 1, idx(q[1]), q[1]);
            } else {
                long long x = q[1], sz = q[2];
                Info info = query(1, 0, m - 1, idx(0), idx(x));
                long long bestGap;
                if (info.minA == INF) bestGap = x - 0;
                else bestGap = max({info.maxGap, info.minA - 0, x - info.maxA});
                ans.push_back(bestGap >= sz);
            }
        }
        return ans;
    }
};

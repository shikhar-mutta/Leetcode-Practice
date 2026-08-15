// Link: https://leetcode.com/problems/block-placement-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> seg;
    int segSize;
    void build(int n) {
        segSize = 1;
        while (segSize < n) segSize <<= 1;
        seg.assign(2 * segSize, 0);
    }
    void pointSet(int i, long long val) {
        i += segSize;
        seg[i] = val;
        for (i >>= 1; i >= 1; i >>= 1) seg[i] = max(seg[2*i], seg[2*i+1]);
    }
    long long rangeMax(int l, int r) { // inclusive, 0-indexed
        if (l > r) return 0;
        l += segSize; r += segSize + 1;
        long long res = 0;
        while (l < r) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(res, seg[--r]);
            l >>= 1; r >>= 1;
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        set<long long> allObstaclesFull; // positions ever placed
        for (auto& q : queries) if (q[0] == 1) allObstaclesFull.insert(q[1]);
        allObstaclesFull.insert(0);

        vector<long long> coordsVec(allObstaclesFull.begin(), allObstaclesFull.end());
        int n = coordsVec.size();
        unordered_map<long long,int> rank;
        for (int i = 0; i < n; i++) rank[coordsVec[i]] = i;

        build(n);
        // active set of obstacle positions, starts with ALL ever placed (reverse start)
        set<long long> active(coordsVec.begin(), coordsVec.end());
        const long long INF = (long long)4e18;

        // initialize gaps
        for (int i = 0; i < n; i++) {
            long long nxt = (i + 1 < n) ? coordsVec[i+1] : INF;
            pointSet(i, nxt - coordsVec[i]);
        }

        int m = queries.size();
        vector<bool> resAt(m, false);
        for (int i = m - 1; i >= 0; i--) {
            if (queries[i][0] == 2) {
                long long x = queries[i][1], sz = queries[i][2];
                auto it = active.upper_bound(x);
                --it; // predecessor <= x
                int predRank = rank[*it];
                long long fullGaps = rangeMax(0, predRank - 1);
                long long storedGap = seg[predRank + segSize];
                long long predUsable = min(storedGap, x - *it);
                long long best = max(fullGaps, predUsable);
                resAt[i] = (best >= sz);
            } else {
                long long p = queries[i][1];
                auto it = active.find(p);
                auto predIt = prev(it);
                auto succIt = next(it);
                long long predPos = *predIt;
                long long succPos = (succIt == active.end()) ? INF : *succIt;
                pointSet(rank[predPos], succPos - predPos);
                pointSet(rank[p], 0); // deactivate
                active.erase(it);
            }
        }
        vector<bool> res;
        for (int i = 0; i < m; i++) if (queries[i][0] == 2) res.push_back(resAt[i]);
        return res;
    }
};

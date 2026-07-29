// Link: https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return robots[a] < robots[b]; });
        vector<long long> pos(n), dist(n);
        for (int i = 0; i < n; i++) { pos[i] = robots[idx[i]]; dist[i] = distance[idx[i]]; }

        vector<long long> w(walls.begin(), walls.end());
        sort(w.begin(), w.end());

        auto countInRange = [&](long long lo, long long hi) -> long long {
            if (lo > hi) return 0;
            auto l = lower_bound(w.begin(), w.end(), lo);
            auto r = upper_bound(w.begin(), w.end(), hi);
            return (long long)(r - l);
        };

        // edge ranges
        long long edgeLeft = countInRange(pos[0] - dist[0], pos[0]);
        long long edgeRight = countInRange(pos[n-1], pos[n-1] + dist[n-1]);

        if (n == 1) {
            return (int)max(edgeLeft, edgeRight);
        }

        // per-gap ranges
        vector<pair<long long,long long>> rightRange(n-1), leftRange(n-1);
        for (int i = 0; i < n - 1; i++) {
            rightRange[i] = {pos[i], min(pos[i] + dist[i], pos[i+1] - 1)};
        }
        for (int i = 1; i < n; i++) {
            leftRange[i-1] = {max(pos[i] - dist[i], pos[i-1] + 1), pos[i]};
        }

        auto gapContrib = [&](int gapIdx, bool prevR, bool curL) -> long long {
            long long cR = 0, cL = 0, cBoth = 0;
            if (prevR) cR = countInRange(rightRange[gapIdx].first, rightRange[gapIdx].second);
            if (curL) cL = countInRange(leftRange[gapIdx].first, leftRange[gapIdx].second);
            if (prevR && curL) {
                long long lo = max(rightRange[gapIdx].first, leftRange[gapIdx].first);
                long long hi = min(rightRange[gapIdx].second, leftRange[gapIdx].second);
                cBoth = countInRange(lo, hi);
            }
            return cR + cL - cBoth;
        };

        // dp[0] = L, dp[1] = R
        vector<long long> dp(2);
        dp[0] = edgeLeft;
        dp[1] = 0;

        for (int i = 1; i < n; i++) {
            vector<long long> ndp(2, LLONG_MIN);
            for (int cur = 0; cur < 2; cur++) { // 0=L,1=R
                bool curL = (cur == 0);
                for (int prev = 0; prev < 2; prev++) {
                    bool prevR = (prev == 1);
                    long long val = dp[prev] + gapContrib(i-1, prevR, curL);
                    ndp[cur] = max(ndp[cur], val);
                }
            }
            dp = ndp;
        }

        long long ans = max(dp[0], dp[1] + edgeRight);
        return (int)ans;
    }
};

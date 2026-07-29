// Link: https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long L = 4LL * side;
        int n = points.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            long long x = points[i][0], y = points[i][1];
            long long t;
            if (y == 0) t = x;
            else if (x == side) t = side + y;
            else if (y == side) t = 2LL * side + (side - x);
            else t = 3LL * side + (side - y);
            pos[i] = t;
        }
        sort(pos.begin(), pos.end());

        vector<long long> pos2(2 * n);
        for (int i = 0; i < 2 * n; i++) pos2[i] = pos[i % n] + (i / n) * L;

        auto feasible = [&](long long d) -> bool {
            if (d == 0) return true;
            for (int i = 0; i < n; i++) {
                long long start = pos2[i];
                long long limit = start + L;
                long long cur = start;
                int cnt = 1;
                int j = i;
                while (cnt < k) {
                    long long need = cur + d;
                    int lo = j + 1, hi = 2 * n - 1, res = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (pos2[mid] >= need) { res = mid; hi = mid - 1; }
                        else lo = mid + 1;
                    }
                    if (res == -1 || pos2[res] >= limit) break;
                    cur = pos2[res];
                    j = res;
                    cnt++;
                }
                if (cnt >= k && (limit - cur) >= d) return true;
            }
            return false;
        };

        long long lo = 0, hi = L / k;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid; else hi = mid - 1;
        }
        return (int)lo;
    }
};

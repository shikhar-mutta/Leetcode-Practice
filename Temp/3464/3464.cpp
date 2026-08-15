// Link: https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long toPos(int side, int x, int y) {
        if (y == 0) return x;
        if (x == side) return (long long)side + y;
        if (y == side) return (long long)3 * side - x;
        return (long long)4 * side - y;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) pos[i] = toPos(side, points[i][0], points[i][1]);
        sort(pos.begin(), pos.end());

        long long perimeter = 4LL * side;
        vector<long long> dpos(2 * n);
        for (int i = 0; i < n; i++) { dpos[i] = pos[i]; dpos[i + n] = pos[i] + perimeter; }

        auto feasible = [&](long long D) -> bool {
            for (int s = 0; s < n; s++) {
                long long limit = pos[s] + perimeter;
                int count = 1;
                long long cur = pos[s];
                int windowEnd = s + n - 1; // inclusive, within dpos
                int idx = s;
                while (count < k) {
                    long long target = cur + D;
                    if (target > limit) break;
                    int lo = idx + 1, hi = windowEnd, res = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (dpos[mid] >= target) { res = mid; hi = mid - 1; }
                        else lo = mid + 1;
                    }
                    if (res == -1 || dpos[res] > limit) break;
                    idx = res;
                    cur = dpos[res];
                    count++;
                }
                if (count >= k && (limit - cur) >= D) return true;
            }
            return false;
        };

        long long lo = 0, hi = perimeter / k, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return (int)ans;
    }
};

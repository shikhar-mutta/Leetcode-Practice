// Link: https://leetcode.com/problems/check-if-the-rectangle-corner-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        int n = circles.size();
        long long X = xCorner, Y = yCorner;

        // check corners blocked
        for (auto& c : circles) {
            long long cx = c[0], cy = c[1], r = c[2];
            if (cx*cx + cy*cy <= r*r) return false;
            long long dx = cx - X, dy = cy - Y;
            if (dx*dx + dy*dy <= r*r) return false;
        }

        auto clamp = [](long long v, long long lo, long long hi) {
            return max(lo, min(hi, v));
        };

        vector<bool> touchLeftTop(n, false), touchBottomRight(n, false);
        for (int i = 0; i < n; i++) {
            long long cx = circles[i][0], cy = circles[i][1], r = circles[i][2];
            // left edge x=0, y in [0,Y]
            {
                long long py = clamp(cy, 0, Y);
                long long dx = cx - 0, dy = cy - py;
                if (dx*dx + dy*dy <= r*r) touchLeftTop[i] = true;
            }
            // top edge y=Y, x in [0,X]
            {
                long long px = clamp(cx, 0, X);
                long long dx = cx - px, dy = cy - Y;
                if (dx*dx + dy*dy <= r*r) touchLeftTop[i] = true;
            }
            // bottom edge y=0, x in [0,X]
            {
                long long px = clamp(cx, 0, X);
                long long dx = cx - px, dy = cy - 0;
                if (dx*dx + dy*dy <= r*r) touchBottomRight[i] = true;
            }
            // right edge x=X, y in [0,Y]
            {
                long long py = clamp(cy, 0, Y);
                long long dx = cx - X, dy = cy - py;
                if (dx*dx + dy*dy <= r*r) touchBottomRight[i] = true;
            }
        }

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a != b) parent[a] = b;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long cx1 = circles[i][0], cy1 = circles[i][1], r1 = circles[i][2];
                long long cx2 = circles[j][0], cy2 = circles[j][1], r2 = circles[j][2];
                long long dx = cx1 - cx2, dy = cy1 - cy2;
                long long rsum = r1 + r2;
                if (dx*dx + dy*dy <= rsum*rsum) unite(i, j);
            }
        }

        unordered_map<int, bool> compLeftTop, compBottomRight;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (touchLeftTop[i]) compLeftTop[root] = true;
            if (touchBottomRight[i]) compBottomRight[root] = true;
        }
        for (auto& [root, val] : compLeftTop) {
            if (val && compBottomRight.count(root) && compBottomRight[root]) return false;
        }

        return true;
    }
};

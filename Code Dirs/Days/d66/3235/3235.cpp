// Link: https://leetcode.com/problems/check-if-the-rectangle-corner-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: the path from (0,0) to (xCorner,yCorner) is blocked iff a chain of overlapping circles connects the "top-or-left" boundary to
//  the "bottom-or-right" boundary (forming a wall separating start and end). Union-Find circles that overlap, plus two virtual nodes for those two boundary groups; a circle unions with a boundary node if its distance to that boundary SEGMENT (not the infinite line — clamped to the segment's actual extent) is <= its radius. Also immediately false if any circle covers either corner. Reachable iff the two boundary groups stay disconnected.
class Solution
{
public:
    bool canReachCorner(int xCorner, int yCorner,
                        vector<vector<int>> &circles)
    {
        using ll = long long;

        auto inCircle = [&](ll x, ll y, ll cx, ll cy, ll r)
        {
            return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
        };

        auto crossLeftTop = [&](ll cx, ll cy, ll r)
        {
            bool a = abs(cx) <= r && cy >= 0 && cy <= yCorner;
            bool b = abs(cy - yCorner) <= r && cx >= 0 && cx <= xCorner;
            return a || b;
        };

        auto crossRightBottom = [&](ll cx, ll cy, ll r)
        {
            bool a = abs(cx - xCorner) <= r && cy >= 0 && cy <= yCorner;
            bool b = abs(cy) <= r && cx >= 0 && cx <= xCorner;
            return a || b;
        };

        int n = circles.size();
        vector<int> vis(n, 0);

        function<bool(int)> dfs = [&](int i)
        {
            vis[i] = 1;
            auto &a = circles[i];
            ll x1 = a[0], y1 = a[1], r1 = a[2];

            if (crossRightBottom(x1, y1, r1))
                return true;

            for (int j = 0; j < n; ++j)
            {
                if (vis[j])
                    continue;
                auto &b = circles[j];
                ll x2 = b[0], y2 = b[1], r2 = b[2];

                ll dx = x1 - x2;
                ll dy = y1 - y2;
                ll rr = r1 + r2;

                if (dx * dx + dy * dy > rr * rr)
                    continue;

                // Connected only if intersection lies inside the rectangle.
                if ((x1 * r2 + x2 * r1) < (r1 + r2) * xCorner &&
                    (y1 * r2 + y2 * r1) < (r1 + r2) * yCorner &&
                    (x1 * r2 + x2 * r1) > 0 && (y1 * r2 + y2 * r1) > 0)
                {
                    if (dfs(j))
                        return true;
                }
            }
            return false;
        };

        for (auto &c : circles)
        {
            if (inCircle(0, 0, c[0], c[1], c[2]) ||
                inCircle(xCorner, yCorner, c[0], c[1], c[2]))
                return false;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i] &&
                crossLeftTop(circles[i][0], circles[i][1], circles[i][2]) &&
                dfs(i))
                return false;
        }

        return true;
    }
};

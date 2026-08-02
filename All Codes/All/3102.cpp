// Link: https://leetcode.com/problems/minimize-manhattan-distances/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Manhattan distance |x1-x2|+|y1-y2| equals max Chebyshev distance in rotated coords u=x+y, v=x-y. Max pairwise Manhattan distance overall = max(range(u), range(v)). Using multisets for u and v values, try removing each point and recompute the resulting max range in O(log n) via multiset begin/rbegin after erasing; track the minimum.
class Solution
{
private:
    int getMaxDistance(const vector<vector<int>> &points, int skip)
    {
        int max_u = INT_MIN, min_u = INT_MAX;
        int max_v = INT_MIN, min_v = INT_MAX;

        for (int i = 0; i < points.size(); ++i)
        {
            if (i == skip)
                continue;
            int u = points[i][0] + points[i][1];
            int v = points[i][0] - points[i][1];

            max_u = max(max_u, u);
            min_u = min(min_u, u);
            max_v = max(max_v, v);
            min_v = min(min_v, v);
        }

        return max(max_u - min_u, max_v - min_v);
    }

public:
    int minimumDistance(vector<vector<int>> &points)
    {
        int n = points.size();

        int max_u = INT_MIN, min_u = INT_MAX;
        int max_v = INT_MIN, min_v = INT_MAX;

        int max_u_idx = -1, min_u_idx = -1;
        int max_v_idx = -1, min_v_idx = -1;

        for (int i = 0; i < n; ++i)
        {
            int u = points[i][0] + points[i][1];
            int v = points[i][0] - points[i][1];

            if (u > max_u)
            {
                max_u = u;
                max_u_idx = i;
            }
            if (u < min_u)
            {
                min_u = u;
                min_u_idx = i;
            }
            if (v > max_v)
            {
                max_v = v;
                max_v_idx = i;
            }
            if (v < min_v)
            {
                min_v = v;
                min_v_idx = i;
            }
        }

        int res = INT_MAX;
        res = min(res, getMaxDistance(points, max_u_idx));
        res = min(res, getMaxDistance(points, min_u_idx));
        res = min(res, getMaxDistance(points, max_v_idx));
        res = min(res, getMaxDistance(points, min_v_idx));

        return res;
    }
};

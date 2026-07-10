// Link: https://leetcode.com/problems/minimum-area-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        unordered_set<int> seen;
        auto key = [](int x, int y)
        { return x * 40001 + y; };
        for (auto &p : points)
            seen.insert(key(p[0], p[1]));

        int n = points.size(), best = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2)
                    continue; // not a diagonal
                if (seen.count(key(x1, y2)) && seen.count(key(x2, y1)))
                    best = min(best, abs(x1 - x2) * abs(y1 - y2));
            }
        return best == INT_MAX ? 0 : best;
    }
};

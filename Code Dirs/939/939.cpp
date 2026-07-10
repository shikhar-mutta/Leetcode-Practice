// Link: https://leetcode.com/problems/minimum-area-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the number of points. We check all pairs of points to see if they can form a rectangle, which takes O(n^2) time.
    // SC: O(n) for storing the points in a set.
    // Approach: We can use a set to store the points for O(1) lookups. We then iterate through all pairs of points and check if they can form a rectangle by checking if the other two corners of the rectangle exist in the set. If they do, we calculate the area of the rectangle and update the minimum area found so far. Finally, we return the minimum area found, or 0 if no rectangle was found.
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

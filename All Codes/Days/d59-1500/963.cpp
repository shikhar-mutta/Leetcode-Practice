// Link: https://leetcode.com/problems/minimum-area-rectangle-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3), SC: O(n)
// Approach: Brute Force
// 1. We will iterate through all the points and check if they can form a rectangle
// 2. We will check if the points can form a rectangle by checking if the diagonals are equal and if the points are not collinear
// 3. If they can form a rectangle, we will calculate the area of the rectangle and update the minimum area
// 4. We will return the minimum area if it is not equal to 1e18, otherwise we will return 0
class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &a)
    {
        int n = a.size();
        double m = 1e18;
        unordered_set<int> b;
        for (int i = 0; i < n; b.insert(a[i][0] * 40001 + a[i][1]), ++i)
            ;
        for (int i = 0; i < n - 2; ++i)
            for (int j = i + 1; j < n - 1; ++j)
                for (int k = j + 1; k < n; ++k)
                {
                    int c = a[i][0], d = a[i][1], e = a[j][0], f = a[j][1], g = a[k][0], h = a[k][1], p = e - c, q = f - d, u = g - c, v = h - d;
                    if (p * u == -q * v && b.find((p + g) * 40001 + q + h) != b.end())
                        m = min(m, sqrt(1LL * (p * p + q * q) * (u * u + v * v)));
                }
        return m != 1e18 ? m : 0;
    }
};

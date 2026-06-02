// Link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int cnt = 0;
        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            int x = abs(points[i][0] - points[i - 1][0]);
            int y = abs(points[i][1] - points[i - 1][1]);
            cnt += max(x, y); // we can move diagonally, so we take the maximum of x and y
        }
        return cnt;
    }
};

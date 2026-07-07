// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(1)
    //  Approach: Sort the points based on the end coordinate of each balloon. Then, iterate through the sorted points and keep track of the position of the last arrow shot. If the start coordinate of the current balloon is greater than the position of the last arrow, we need to shoot a new arrow at the end coordinate of the current balloon. Otherwise, we can burst the current balloon with the last arrow shot.
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int arrows = 0;
        long long arrowPos = LLONG_MIN; // coordinates reach INT_MIN/INT_MAX
        for (auto &p : points)
        {
            if (p[0] > arrowPos)
            {
                arrows++;
                arrowPos = p[1];
            }
        }
        return arrows;
    }
};

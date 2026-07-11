// Link: https://leetcode.com/problems/k-closest-points-to-origin/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) for finding the k closest points using nth_element
    // SC: O(1) for in-place partitioning
    // Approach:
    //  1. Use the nth_element algorithm to partition the points based on their distance from the origin.
    //  2. The first k points in the partitioned array will be the k closest points to the origin.
    //  3. Sort the first k points based on their distance from the origin to return them in ascending order.
    //  4. Return the first k points as the result.
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto dist = [](const vector<int> &p)
        { return (long long)p[0] * p[0] + (long long)p[1] * p[1]; };
        nth_element(points.begin(), points.begin() + k - 1, points.end(),
                    [&](const vector<int> &a, const vector<int> &b)
                    { return dist(a) < dist(b); });
        sort(points.begin(), points.begin() + k,
             [&](const vector<int> &a, const vector<int> &b)
             { return dist(a) < dist(b); });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

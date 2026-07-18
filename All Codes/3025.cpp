// Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + m^2), SC: O(1)
    //  Approach:
    //  1. Sort the points based on the x-coordinate in ascending order. If two points have the same x-coordinate, sort them based on the y-coordinate in descending order.
    //  2. Initialize a variable count to 0 to keep track of the number of valid pairs.
    //  3. Iterate through each point in the sorted points array:
    //     a. For each point, iterate through the remaining points in the array:
    //        i. If the y-coordinate of the current point is less than or equal to the y-coordinate of the other point and greater than the maximum y-coordinate encountered so far, increment the count and update the maximum y-coordinate.
    //  4. Return the count as the number of valid pairs of points that can be formed based on the given conditions.
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; });

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int max_y = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                if (points[j][1] <= points[i][1] && points[j][1] > max_y)
                {
                    count++;
                    max_y = points[j][1];
                }
            }
        }

        return count;
    }
};

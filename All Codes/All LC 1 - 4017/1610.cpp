// Link: https://leetcode.com/problems/maximum-number-of-visible-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach: We can use a grid bucket to count overlapping points and then extract unique angles and their weights. We can then sort the unique angles and use a sliding window approach to find the maximum number of visible points within the given angle. Finally, we add the number of overlapping points to the result.
class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle,
                      vector<int> &location)
    {
        int x0 = location[0];
        int y0 = location[1];
        int sameLoc = 0;
        // 1. Grid bucket to count overlapping points
        // Constraints say 0 <= x, y <= 100, so a 101x101 grid covers all
        // possibilities
        int grid[101][101] = {0};

        for (const auto &p : points)
        {
            if (p[0] == x0 && p[1] == y0)
            {
                sameLoc++;
            }
            else
            {
                grid[p[0]][p[1]]++;
            }
        }
        // Structure to bind an angle to the number of points at that angle
        struct AngleWeight
        {
            double angle;
            int weight;
        };
        vector<AngleWeight> uniqueAngles;
        uniqueAngles.reserve(10201); // Max possible unique coordinates
        // 2. Extract unique angles and their weights
        for (int x = 0; x <= 100; ++x)
        {
            for (int y = 0; y <= 100; ++y)
            {
                if (grid[x][y] > 0)
                {
                    double agl = atan2(y - y0, x - x0) * 180.0 / M_PI;
                    if (agl < 0)
                        agl += 360.0;
                    uniqueAngles.push_back({agl, grid[x][y]});
                }
            }
        }
        // 3. Sort strictly unique angles
        sort(uniqueAngles.begin(), uniqueAngles.end(),
             [](const AngleWeight &a, const AngleWeight &b)
             {
                 return a.angle < b.angle;
             });
        int u = uniqueAngles.size();
        // Lambdas for our virtual circular array
        auto getAngle = [&](int idx)
        {
            return uniqueAngles[idx % u].angle + (idx >= u ? 360.0 : 0.0);
        };
        auto getWeight = [&](int idx)
        { return uniqueAngles[idx % u].weight; };
        int right = 0;
        int maxVisible = 0;
        int currentPointsInWindow = 0;
        constexpr double eps = 1e-9;
        // 4. Weighted O(1) Space Sliding Window
        for (int i = 0; i < u; i++)
        {
            // Expand the window and add weights
            while (right < i + u &&
                   getAngle(right) - getAngle(i) <= angle + eps)
            {
                currentPointsInWindow += getWeight(right);
                right++;
            }
            maxVisible = max(maxVisible, currentPointsInWindow);
            // Shrink the window: subtract the weight of the outgoing point
            currentPointsInWindow -= getWeight(i);
        }
        return maxVisible + sameLoc;
    }
};
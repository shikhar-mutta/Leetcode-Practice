// Link: https://leetcode.com/problems/max-points-on-a-line/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) due to sorting slopes
// SC: O(n) for storing slopes
// Approach:
// 1. Iterate through each point as a base point.
// 2. For each base point, calculate the slope to every other point.
// 3. Use a hash map to count the frequency of each slope.
// 4. Handle duplicates and vertical lines separately.
// 5. The maximum number of points on a line through the base point is the maximum frequency of any slope plus duplicates plus the base point itself.
// 6. Return the maximum number of points found across all base points.
class Solution
{
public:
    int maxPoints(std::vector<std::vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;

        int max_points = 0;

        for (int i = 0; i < n; ++i)
        {
            int duplicates = 0;
            std::vector<int> slopes;
            slopes.reserve(n - i); // Prevent reallocations

            for (int j = i + 1; j < n; ++j)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Handle duplicates safely
                if (dx == 0 && dy == 0)
                {
                    duplicates++;
                    continue;
                }

                // Reduce to simplest form
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Canonicalize: force dx to be positive. If dx == 0, force dy to be positive.
                if (dx < 0 || (dx == 0 && dy < 0))
                {
                    dx = -dx;
                    dy = -dy;
                }

                // BIT PACKING:
                // dy needs 16 bits (offset by 20000 to make it positive: 0 to 40000)
                // dx needs 15 bits (0 to 20000)
                // Total = 31 bits. Fits perfectly in a 32-bit signed int.
                int packed_slope = ((dy + 20000) << 15) | dx;
                slopes.push_back(packed_slope);
            }

            // Sort the packed slopes. Identical slopes will be adjacent.
            std::sort(slopes.begin(), slopes.end());

            // Count the maximum frequency of any single slope
            int current_max = 0;
            int count = 0;
            for (size_t k = 0; k < slopes.size(); ++k)
            {
                if (k == 0 || slopes[k] == slopes[k - 1])
                {
                    count++;
                }
                else
                {
                    current_max = std::max(current_max, count);
                    count = 1;
                }
            }
            current_max = std::max(current_max, count); // Catch the last group

            // Total points = max slope frequency + duplicates + the base point 'i'
            max_points = std::max(max_points, current_max + duplicates + 1);
        }

        return max_points;
    }
};
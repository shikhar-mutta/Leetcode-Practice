// Link: https://leetcode.com/problems/maximum-points-inside-the-square/description/

#include <bits/stdc++.h>
using namespace std;

struct Solution
{
    // TC: O(n)
    // SC: O(1)
    // Approach:
    //  1. Create an array of size 26 to store the minimum distance of each character from the origin.
    //  2. Iterate through the points and update the minimum distance for each character.
    //  3. Calculate the maximum distance of the square that can be formed with the points and the characters.
    //  4. Count the number of characters that have a minimum distance less than the maximum distance of the square.
    //  5. Return the count of characters.
    static constexpr int maxPointsInsideSquare(const std::vector<std::vector<int>> &points, std::string_view s) noexcept
    {
        int min[26];
        std::ranges::fill(min, std::numeric_limits<int>::max());
        int r = std::numeric_limits<int>::max();

        for (std::size_t i = 0; i != points.size(); ++i)
        {
            int &m = min[s[i] - 'a'];
            int dist = std::max(std::abs(points[i][0]), std::abs(points[i][1]));
            if (dist < m)
                std::swap(m, dist);
            r = std::min(r, dist);
        }

        int result = 0;
        for (int m : min)
            result += m < r;
        return result;
    }
};
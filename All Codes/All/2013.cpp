// Link: https://leetcode.com/problems/detect-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of points added
// SC: O(n) where n is the number of points added
// Approach:
// 1. We will use a hash map to store the count of points added.
// 2. For each point, we will check if we can form a square with the given point as one of the corners.
// 3. We will iterate through all the points with the same x-coordinate and check if we can form a square with the given point as one of the corners
class DetectSquares
{
    std::unordered_map<int, std::unordered_map<int, int>> point_counts;

public:
    void add(std::vector<int> point)
    {
        ++point_counts[point.front()][point.back()];
    }

    int count(std::vector<int> point)
    {
        const auto x1 = point.front();
        const auto y1 = point.back();
        auto it1 = point_counts.find(x1);
        if (it1 == point_counts.end())
        {
            return 0;
        }

        int result = 0;

        for (const auto &[y2, count2] : it1->second)
        {
            if (y2 == y1)
            {
                continue;
            }
            const int h = std::abs(y1 - y2);
            const int x_left = x1 - h;
            const int x_right = x1 + h;
            auto it_left = point_counts.find(x_left);

            if (it_left != point_counts.end())
            {
                const auto &y_map = it_left->second;
                auto it_y1 = y_map.find(y1);
                auto it_y2 = y_map.find(y2);
                if (it_y1 != y_map.end() && it_y2 != y_map.end())
                {
                    result += count2 * it_y1->second * it_y2->second;
                }
            }

            auto it_right = point_counts.find(x_right);

            if (it_right != point_counts.end())
            {
                const auto &y_map = it_right->second;
                auto it_y1 = y_map.find(y1);
                auto it_y2 = y_map.find(y2);
                if (it_y1 != y_map.end() && it_y2 != y_map.end())
                {
                    result += count2 * it_y1->second * it_y2->second;
                }
            }
        }
        return result;
    }
};

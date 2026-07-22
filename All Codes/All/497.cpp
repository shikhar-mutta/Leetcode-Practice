// Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logN) for pick() and O(N) for constructor
// SC: O(N) for constructor and O(1) for pick()
// Approach:
//  1. In the constructor, we calculate the area of each rectangle and store the cumulative area in a vector called weights. This allows us to randomly select a rectangle based on its area.
//  2. In the pick() function, we generate a random number between 1 and the total area of all rectangles. We then use binary search to find the rectangle that corresponds to this random number. Finally, we generate a random point within the selected rectangle and return it.
// 3. The random number generation is done using the Mersenne Twister engine (std::mt19937) and uniform distributions to ensure that each point within the rectangles has an equal probability of being selected.
class Solution
{
    std::vector<std::vector<int>> rects;
    std::vector<int> weights;
    std::mt19937 rng{std::random_device{}()};

public:
    Solution(std::vector<std::vector<int>> &rects) : rects(rects)
    {
        int total = 0;
        for (auto &r : rects)
        {
            total += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            weights.push_back(total);
        }
    }

    std::vector<int> pick()
    {
        int total = weights.back();
        int target = std::uniform_int_distribution<int>(1, total)(rng);
        int idx = (int)(std::lower_bound(weights.begin(), weights.end(), target) - weights.begin());
        auto &r = rects[idx];
        int x = std::uniform_int_distribution<int>(r[0], r[2])(rng);
        int y = std::uniform_int_distribution<int>(r[1], r[3])(rng);
        return {x, y};
    }
};

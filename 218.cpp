// Link: https://leetcode.com/problems/the-skyline-problem/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//  Approach: We use a priority queue to keep track of the current maximum height of the buildings. We iterate through the buildings and for each building, we add its height and end position to the priority queue. We also check if the current maximum height has changed, and if so, we add a new point to the skyline. Finally, we continue to pop from the priority queue until we reach the end of the last building, adding points to the skyline as necessary.
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &bldg)
    {
        priority_queue<pair<int, int>> H; // (h, end) pairs
        H.emplace(0, INT_MAX);            // the ground extends all the way to the right
        vector<vector<int>> skyline;
        skyline.reserve(2 * bldg.size());

        for (const auto &bld : bldg)
        {
            while (H.top().second < bld[0])
            {
                // Emit the skyline until s = bld[0].
                const auto p = H.top();
                while (H.size() > 1 and H.top().second <= p.second)
                    H.pop();
                skyline.push_back({p.second, H.top().first});
            }
            H.emplace(bld[2], bld[1]); // Insert (h,end) for the current bld

            // If the last point in the skyline has the same x-coordinate as the current building's start, update its height if necessary. Otherwise, add a new point to the skyline.
            if (!skyline.empty() and skyline.back()[0] == bld[0] and skyline.back()[1] < bld[2])
                skyline.back()[1] = bld[2];
            else if (skyline.empty() or H.top().first != skyline.back()[1])
                skyline.push_back({bld[0], bld[2]});
        }

        while (H.size() > 1)
        {
            const auto p = H.top();
            // Emit the skyline until the end of the last building.
            while (H.size() > 1 and H.top().second <= p.second)
                H.pop();
            skyline.push_back({p.second, H.top().first});
        }
        return skyline;
    }
};

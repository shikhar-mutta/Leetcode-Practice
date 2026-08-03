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

class Solution1
{
public:
    // TC: O(nlogn), SC: O(n)
    // Approach: We use a sweep line algorithm to find the skyline of a set of buildings. We create events for the start and end of each building, sort them, and then process them in order. We maintain a multiset of active building heights to determine the current maximum height at each x-coordinate.
    // The main difference between this implementation and the previous one is that this one uses a more concise approach to handle the events and the multiset of heights.
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        // event per building: start encoded as -height, end as +height
        vector<pair<int, int>> points;
        for (auto bi : buildings)
        {
            points.push_back({bi[0], -bi[2]});
            points.push_back({bi[1], bi[2]});
        }
        // must sweep left to right; also puts same-x starts (negative) before ends (positive)
        sort(points.begin(), points.end());

        // seed with ground level 0 so *st.rbegin() is always valid, even once every building has ended
        multiset<int> st = {0};
        vector<vector<int>> res;
        int prMx = 0;
        for (auto pt : points)
        {
            if (pt.second > 0)
            {
                st.erase(st.find(pt.second)); // building ends, drop its height
            }
            else
            {
                st.insert(-pt.second); // building starts, add its height
            }
            int ctMx = *st.rbegin();
            if (ctMx != prMx) // catch drops too, not just increases
            {
                res.push_back({pt.first, ctMx});
                prMx = ctMx;
            }
        }
        return res;
    }
};

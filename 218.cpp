// Link: https://leetcode.com/problems/the-skyline-problem/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    // Approach: We use a sweep line algorithm to find the skyline of a set of buildings. We create events for the start and end of each building, sort them, and then process them in order. We maintain a multiset of active building heights to determine the current maximum height at each x-coordinate.
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        // events: (x, -h) = building starts, (x, h) = building ends.
        // Sorting then handles ties right: at equal x, starts before ends,
        // taller starts first, shorter ends first.
        vector<pair<int, int>> events;
        events.reserve(buildings.size() * 2);
        for (auto &b : buildings)
        {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());

        multiset<int> alive = {0}; // heights currently overlapping the sweep line
        vector<vector<int>> res;
        int prev = 0;
        for (auto &[x, h] : events)
        {
            if (h < 0)
                alive.insert(-h);
            else
                alive.erase(alive.find(h));
            int cur = *alive.rbegin();
            if (cur != prev)
            {
                res.push_back({x, cur});
                prev = cur;
            }
        }
        return res;
    }
};

// Link: https://leetcode.com/problems/rectangle-area-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: Use a sweep line algorithm to find the total area covered by the rectangles. For each x-coordinate, maintain a list of active y-intervals and calculate the total covered y-length.
// The total area is then the sum of the covered y-length multiplied by the width of the x-intervals. Use a vector to store events for each rectangle's start and end x-coordinates, and sort them. For each event, update the active y-intervals and calculate the area contribution.
class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        vector<vector<int>> events;
        for (auto &it : rectangles)
        {
            events.push_back({it[0], 1, it[1], it[3]});
            events.push_back({it[2], -1, it[1], it[3]});
        }
        sort(events.begin(), events.end());
        int prev_x = events[0][0];
        const int mod = 1e9 + 7;
        vector<pair<int, int>> active;
        long long total_area = 0LL;
        for (int i = 0; i < events.size(); i++)
        {
            int curr_x = events[i][0];
            int mark = events[i][1];
            int y_start = events[i][2];
            int y_end = events[i][3];

            int width = curr_x - prev_x;
            long long covered_y = 0;
            if (width > 0 && active.size() > 0)
            {
                sort(active.begin(), active.end());
                long long ys = active[0].first;
                long long ye = active[0].second;
                for (int k = 0; k < active.size(); k++)
                {
                    if (active[k].first > ye)
                    {
                        covered_y += (ye - ys);
                        ys = active[k].first;
                        ye = active[k].second;
                    }
                    else
                    {
                        ye = max(ye, 1LL * active[k].second);
                    }
                }
                covered_y += (ye - ys);
                total_area =
                    (total_area + (1LL * width * covered_y) % mod) % mod;
            }
            if (mark == 1)
            {
                active.push_back({y_start, y_end});
            }
            else
            {
                for (int j = 0; j < active.size(); j++)
                {
                    if (active[j].first == y_start &&
                        active[j].second == y_end)
                    {
                        active.erase(active.begin() + j);
                        break;
                    }
                }
            }
            prev_x = curr_x;
        }
        return total_area % mod;
    }
};
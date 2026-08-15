// Link: https://leetcode.com/problems/my-calendar-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) and SC: O(n)
//  Approach:
//  1. We maintain two lists: one for all booked intervals and another for all overlapping intervals.
//  2. When booking a new interval, we first check if it overlaps with any existing overlapping intervals. If it does, we return false to prevent triple booking.
//  3. If there is no triple booking risk, we then check for overlaps with the booked intervals and add any new overlaps to the overlaps list.
//  4. Finally, we add the new interval to the booked list and return true to indicate a successful booking.
class MyCalendarTwo
{
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;

public:
    bool book(int start, int end)
    {

        // Step 1: check triple booking risk
        for (auto &iv : overlaps)
        {
            if (max(start, iv.first) < min(end, iv.second))
            {
                return false;
            }
        }

        // Step 2: update overlaps with intersections from booked
        for (auto &iv : booked)
        {
            int s = max(start, iv.first);
            int e = min(end, iv.second);

            if (s < e)
            {
                overlaps.push_back({s, e});
            }
        }

        // Step 3: add to booked
        booked.push_back({start, end});
        return true;
    }
};
// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of events.
    // SC: O(n) for storing the end days of open events in a priority queue
    // Approach:
    // 1. Sort the events by their start days.
    // 2. Use a priority queue to keep track of the end days of open events.
    // 3. For each day, attend the event that ends the soonest among the open events.
    // 4. If there are no open events, jump to the next event's start day.
    // 5. Repeat until all events have been processed.
    int maxEvents(vector<vector<int>> &events)
    {
        // Greedy: each day, among events already open, attend the one ending soonest.
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> ends; // end days of open events
        int n = events.size(), i = 0, attended = 0, day = 0;
        while (i < n || !ends.empty())
        {
            if (ends.empty())
                day = max(day, events[i][0]); // jump to next event's start
            while (i < n && events[i][0] <= day)
                ends.push(events[i++][1]);
            while (!ends.empty() && ends.top() < day)
                ends.pop(); // expired
            if (!ends.empty())
            {
                ends.pop(); // attend it
                attended++;
                day++;
            }
        }
        return attended;
    }
};

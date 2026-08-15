// Link: https://leetcode.com/problems/my-calendar-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) and SC: O(n)
//  Approach:
//  1. We use a map to store the booked intervals, where the key is the start time and the value is the end time of the interval.
//  2. When booking a new interval, we use lower_bound to find the first interval that starts after or at the same time as the new interval's start time.
//  3. We check if this interval overlaps with the new interval. If it does, we return false to prevent double booking.
//  4. We also check the previous interval (if it exists) to see if it overlaps with the new interval. If it does, we return false to prevent double booking.
//  5. If there are no overlaps, we add the new interval to the map and return true to indicate a successful booking.
class MyCalendar
{
    map<int, int> booked;

public:
    MyCalendar() {}

    bool book(int startTime, int endTime)
    {
        auto it = booked.lower_bound(startTime);

        if (it != booked.end() && it->first < endTime)
            return false;

        if (it != booked.begin() && prev(it)->second > startTime)
            return false;

        booked[startTime] = endTime;
        return true;
    }
};
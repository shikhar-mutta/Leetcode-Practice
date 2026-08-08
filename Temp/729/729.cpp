// Link: https://leetcode.com/problems/my-calendar-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
// Approach: store booked intervals in a map keyed by start; a new [start,end) is valid if it doesn't overlap the interval before or after it.
class MyCalendar {
    map<int,int> events; // start -> end
public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        auto it = events.lower_bound(startTime);
        if (it != events.end() && it->first < endTime) return false;
        if (it != events.begin()) {
            auto prev = std::prev(it);
            if (prev->second > startTime) return false;
        }
        events[startTime] = endTime;
        return true;
    }
};

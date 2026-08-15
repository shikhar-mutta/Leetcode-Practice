// Link: https://leetcode.com/problems/my-calendar-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) per op SC: O(n)
// Approach: track all booked intervals and separately all double-booked (overlap) intervals. A new event is rejected if it overlaps any existing double-booking (would create a triple). Otherwise add its overlap with existing single bookings to the double-booked list, then add the event itself.
class MyCalendarTwo {
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlaps;
public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        for (auto& [s, e] : overlaps) {
            if (startTime < e && s < endTime) return false;
        }
        for (auto& [s, e] : bookings) {
            int lo = max(s, startTime), hi = min(e, endTime);
            if (lo < hi) overlaps.push_back({lo, hi});
        }
        bookings.push_back({startTime, endTime});
        return true;
    }
};

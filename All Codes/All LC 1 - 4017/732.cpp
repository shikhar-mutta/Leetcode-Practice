// Link: https://leetcode.com/problems/my-calendar-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) per book() call  SC: O(n)
//  Approach: maintain a map of time points to their event counts. For each booking,
//  insert start and end points, then update the event counts for all intervals
//  between them, keeping track of the maximum overlap.
class MyCalendarThree
{
public:
    MyCalendarThree() { events.emplace(0, 0); }

    int book(int start, int end)
    {
        auto sit =
            events.emplace(start, prev(events.upper_bound(start))->second)
                .first;
        auto eit =
            events.emplace(end, prev(events.upper_bound(end))->second).first;
        for (; sit != eit; ++sit)
        {
            count = max(count, ++(sit->second));
        }
        return count;
    }

private:
    map<int, int> events;
    int count = 0;
};
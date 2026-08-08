// Link: https://leetcode.com/problems/my-calendar-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) per op SC: O(n)
// Approach: sweep-line with a delta map — +1 at start, -1 at end; on each book, apply the delta and scan accumulated prefix sums to find the new max overlap.
class MyCalendarThree {
    map<int,int> delta;
public:
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        delta[startTime]++;
        delta[endTime]--;
        int cur = 0, best = 0;
        for (auto& [k, v] : delta) {
            cur += v;
            best = max(best, cur);
        }
        return best;
    }
};

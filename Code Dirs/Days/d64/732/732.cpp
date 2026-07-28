// Link: https://leetcode.com/problems/my-calendar-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2) worst case (O(n) map ops per booking, each O(n))  SC: O(n)
// Approach: sweep-line difference map: +1 at start, -1 at end for each
// booking. After each insert, scan the map accumulating the running sum
// to find the new maximum overlap (k-booking count).
class MyCalendarThree {
    map<int,int> delta;
public:
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        delta[startTime]++;
        delta[endTime]--;
        int cur = 0, best = 0;
        for (auto& [t, d] : delta) {
            cur += d;
            best = max(best, cur);
        }
        return best;
    }
};

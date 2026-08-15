// Link: https://leetcode.com/problems/meeting-rooms/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1) extra
// Approach: sort by start time, a valid non-overlapping schedule requires each meeting's start
// to be >= the previous meeting's end
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};

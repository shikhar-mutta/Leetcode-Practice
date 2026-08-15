// Link: https://leetcode.com/problems/meeting-rooms-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort by start, min-heap of end times for rooms in use; reuse a room only if its end
// time is strictly less than the new meeting's start, else allocate a new room
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto& iv : intervals) {
            if (!heap.empty() && heap.top() <= iv[0]) heap.pop();
            heap.push(iv[1]);
        }
        return heap.size();
    }
};

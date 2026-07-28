// Link: https://leetcode.com/problems/course-schedule-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: sort courses by deadline. Greedily take each course,
// tracking total time in a max-heap of durations; if the total exceeds
// the current deadline, evict the longest-duration course taken so far
// (it's safe since a shorter substitute always fits at least as well).
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        long long total = 0;
        for (auto& c : courses) {
            int dur = c[0], deadline = c[1];
            total += dur;
            maxHeap.push(dur);
            if (total > deadline) {
                total -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};

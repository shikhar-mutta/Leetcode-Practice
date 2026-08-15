// Link: https://leetcode.com/problems/course-schedule-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: sort by deadline; greedily take each course, tracking total time in a max-heap; if adding exceeds the deadline, evict the longest course taken so far (swap only if it reduces total time).
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        priority_queue<int> pq;
        long long total = 0;
        for (auto& c : courses) {
            int dur = c[0], dl = c[1];
            total += dur;
            pq.push(dur);
            if (total > dl) {
                total -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

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
        int n = courses.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            int u = courses[i][0];
            int v = courses[i][1];

            p.push_back({v, u});
        }

        sort(p.begin(), p.end());
        /*
        {deadline,duration};

        {200,100},{1250,1000},{1300,200},{3200,2000}

        {5,5},{6,2},{6,4};


        */
        priority_queue<int> pq;
        int day = 0;
        for (int i = 0; i < n; i++) {
            int duration = p[i].second;
            int deadline = p[i].first;
            if (day + duration <= deadline) {
                // ans++;
                pq.push(duration);
                day = day + duration;
            } else {
                if (pq.size() && pq.top() > duration) {
                    day += duration - pq.top();
                    pq.pop();
                    pq.push(duration);
                }
            }
        }

        return pq.size();
    }
};
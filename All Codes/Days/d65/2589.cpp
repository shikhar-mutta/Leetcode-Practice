// Link: https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*maxTime), SC: O(maxTime)
// Approach: sort tasks by end time; greedily reuse already-"on" points within [start,end], and
// for any shortfall, turn on the latest still-off points closest to end (maximizes overlap
// reuse for later tasks). Answer is the total count of "on" points.
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        int maxT = 0;
        for (auto& t : tasks) maxT = max(maxT, t[1]);
        vector<bool> used(maxT + 1, false);

        for (auto& t : tasks) {
            int s = t[0], e = t[1], d = t[2];
            int cnt = 0;
            for (int i = s; i <= e; i++) if (used[i]) cnt++;
            int need = d - cnt;
            for (int i = e; i >= s && need > 0; i--) {
                if (!used[i]) { used[i] = true; need--; }
            }
        }

        int ans = 0;
        for (bool b : used) if (b) ans++;
        return ans;
    }
};

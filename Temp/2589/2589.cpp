// Link: https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

        int maxEnd = 0;
        for (auto &t : tasks) maxEnd = max(maxEnd, t[1]);
        vector<bool> on(maxEnd + 1, false);

        for (auto &t : tasks) {
            int start = t[0], end = t[1], duration = t[2];
            int count = 0;
            for (int i = start; i <= end; i++) if (on[i]) count++;
            int need = duration - count;
            for (int i = end; i >= start && need > 0; i--) {
                if (!on[i]) { on[i] = true; need--; }
            }
        }

        int total = 0;
        for (bool b : on) if (b) total++;
        return total;
    }
};

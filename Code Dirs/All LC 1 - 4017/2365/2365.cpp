// Link: https://leetcode.com/problems/task-scheduler-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> lastDay;
        long long day = 0;
        for (int t : tasks) {
            day++;
            if (lastDay.count(t)) {
                long long earliest = lastDay[t] + space + 1;
                if (day < earliest) day = earliest;
            }
            lastDay[t] = day;
        }
        return day;
    }
};

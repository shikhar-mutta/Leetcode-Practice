// Link: https://leetcode.com/problems/task-scheduler-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach:
// 1. Use a hash map to store the next available day for each task type.
// 2. Iterate through the tasks, and for each task, check if it can be executed on the current day or if we need to wait for the cooldown period.
// 3. Update the next available day for the task type after executing it.
// 4. Return the total number of days taken to execute all tasks.
class Solution
{
public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, long long> nextDay;
        long long day = 0;
        for (int t : tasks)
        {
            ++day;
            auto it = nextDay.find(t);
            if (it != nextDay.end() && day < it->second)
                day = it->second;         // wait out the cooldown
            nextDay[t] = day + space + 1; // earliest this type may run again
        }
        return day;
    }
};
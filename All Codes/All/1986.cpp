// Link: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) where n is the number of tasks
//  SC: O(n) where n is the number of tasks
//  Approach: Backtracking with pruning
//  1. Sort the tasks in descending order to improve pruning
//  2. Use backtracking to try to assign tasks to sessions
//  3. If the number of sessions used is greater than or equal to the best found so far, prune the search
//  4. If all tasks are assigned, update the best
class Solution
{
public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        sort(tasks.rbegin(), tasks.rend()); // largest first improves pruning
        int best = n;                       // worst case: one task per session
        vector<int> sessions;
        backtrack(tasks, 0, sessions, sessionTime, best);
        return best;
    }

private:
    void backtrack(vector<int> &tasks, int i, vector<int> &sessions, int cap,
                   int &best)
    {
        if (sessions.size() >= best)
            return; // prune: can't improve
        if (i == tasks.size())
        {
            best = min(best, (int)sessions.size());
            return;
        }
        for (int s = 0; s < sessions.size(); ++s)
        {
            if (sessions[s] + tasks[i] <= cap)
            {
                sessions[s] += tasks[i];
                backtrack(tasks, i + 1, sessions, cap, best);
                sessions[s] -= tasks[i];
            }
        }
        // try a new session
        sessions.push_back(tasks[i]);
        backtrack(tasks, i + 1, sessions, cap, best);
        sessions.pop_back();
    }
};

// Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(nlogn + mlogm + log(min(n, m)) * min(n, m))  SC: O(min(n, m))
//Approach: Sort tasks and workers. Use binary search to find the maximum number of tasks that can be assigned. For each mid value, use a deque to keep track of available workers and check if the tasks can be assigned with the given number of pills and strength.
class Solution
{
public:
    bool canAssign(vector<int> &tasks, vector<int> &workers, int pills,
                   int strength, int k)
    {
        deque<int> dq;
        int w = workers.size() - 1;

        for (int i = k - 1; i >= 0; i--)
        {
            if (!dq.empty() && dq.front() >= tasks[i])
            {
                dq.pop_front();
            }
            else if (w >= 0 && workers[w] >= tasks[i])
            {
                w--;
            }
            else
            {
                while (w >= 0 && workers[w] + strength >= tasks[i])
                {
                    dq.push_back(workers[w--]);
                }
                if (dq.empty() || pills == 0)
                    return false;
                dq.pop_back();
                pills--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                      int strength)
    {
        int m = tasks.size(), n = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0, r = min(m, n), ans = 0;

        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (canAssign(tasks, workers, pills, strength, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};

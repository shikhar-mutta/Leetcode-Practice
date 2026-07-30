// Link: https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + n*max(end-start)), SC: O(n)
//  Approach: We can use a binary indexed tree (BIT) to keep track of the number of tasks completed at each time. We can sort the tasks by their end time and iterate through them. For each task, we can check how many tasks have been completed in the time range [start, end] using the BIT. If the number of tasks completed is less than the required number of tasks, we can add the remaining tasks to the BIT and update the number of tasks completed. Finally, we can return the total number of tasks completed.
class Solution
{
public:
    int bt[2002] = {}, n = 2001;
    int prefix_sum(int i)
    {
        int sum = 0;
        for (i = i + 1; i > 0; i -= i & (-i))
            sum += bt[i];
        return sum;
    }
    void add(int i, int val)
    {
        for (i = i + 1; i <= n; i += i & (-i))
            bt[i] += val;
    }
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(begin(tasks), end(tasks),
             [](const auto &t1, const auto &t2)
             { return t1[1] < t2[1]; });
        for (const auto &t : tasks)
        {
            int start = t[0], end = t[1], d = t[2];
            d -= prefix_sum(end) - prefix_sum(start - 1);
            for (int i = end; d > 0; --i)
                if (prefix_sum(i) == prefix_sum(i - 1))
                {
                    add(i, 1);
                    --d;
                }
        }
        return prefix_sum(n - 1);
    }
};

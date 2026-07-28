// Link: https://leetcode.com/problems/finish-time-of-tasks-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: Use a topological sort to process tasks in order of dependencies. For each task, calculate the finish time based on the maximum finish time of its children and its own base time.
//  The finish time of a task is the maximum of the finish times of its children plus its own base time. If a task has no children, its finish time is simply its base time. The algorithm uses a queue to process tasks that are ready to be completed (i.e., all their dependencies have been satisfied).
class Solution
{
    static constexpr int maximum_task_count = 100000 + 5;

    inline static int parent[maximum_task_count];
    inline static int remaining_children[maximum_task_count];
    inline static int ready_tasks[maximum_task_count];
    inline static long long minimum_child_finish[maximum_task_count];
    inline static long long maximum_or_finish[maximum_task_count];

public:
    long long finishTime(int n, vector<vector<int>> &edges,
                         vector<int> &baseTime)
    {
        int *base_time = baseTime.data();

        if (n == 1)
        {
            return base_time[0];
        }

        memset(remaining_children, 0, n * sizeof(int));
        memset(maximum_or_finish, 0, n * sizeof(long long));

        for (int edge_index = 0, edge_count = n - 1; edge_index < edge_count;
             ++edge_index)
        {
            int *edge = edges[edge_index].data();
            int parent_task = edge[0];
            int child_task = edge[1];

            parent[child_task] = parent_task;
            ++remaining_children[parent_task];
        }

        int *ready_writer = ready_tasks;

        for (int task = 1; task < n; ++task)
        {
            if (remaining_children[task] == 0)
            {
                maximum_or_finish[task] = base_time[task];
                *ready_writer++ = task;
            }
        }

        for (int *ready_reader = ready_tasks;; ++ready_reader)
        {
            int current_task = *ready_reader;
            int parent_task = parent[current_task];
            long long current_finish = maximum_or_finish[current_task];
            long long parent_maximum_finish = maximum_or_finish[parent_task];

            if (parent_maximum_finish == 0)
            {
                if (--remaining_children[parent_task] != 0)
                {
                    minimum_child_finish[parent_task] = current_finish;
                    maximum_or_finish[parent_task] = current_finish;
                    continue;
                }

                long long parent_finish =
                    current_finish + base_time[parent_task];

                if (parent_task == 0)
                {
                    return parent_finish;
                }

                maximum_or_finish[parent_task] = parent_finish;
                *ready_writer++ = parent_task;
                continue;
            }

            if (current_finish < minimum_child_finish[parent_task])
            {
                minimum_child_finish[parent_task] = current_finish;
            }
            else if (current_finish > parent_maximum_finish)
            {
                parent_maximum_finish = current_finish;
                maximum_or_finish[parent_task] = current_finish;
            }

            if (--remaining_children[parent_task] != 0)
            {
                continue;
            }

            long long parent_finish =
                parent_maximum_finish + parent_maximum_finish -
                minimum_child_finish[parent_task] + base_time[parent_task];

            if (parent_task == 0)
            {
                return parent_finish;
            }

            maximum_or_finish[parent_task] = parent_finish;
            *ready_writer++ = parent_task;
        }
    }
};
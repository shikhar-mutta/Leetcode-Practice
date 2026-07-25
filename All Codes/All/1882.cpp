// Link: https://leetcode.com/problems/process-tasks-using-servers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m log n) where m is the number of tasks and n is the number of servers
// SC: O(n) where n is the number of servers
// Approach: Priority Queue
//   1. Create two priority queues, one for available servers and one for busy servers
//   2. For each task, check if there are any available servers. If there are, assign the task to the server with the smallest weight and index. If there are no available servers, wait until the next server becomes available and assign the task to that server.
//   3. Return the index of the server assigned to each task.
class Solution
{
public:
    typedef pair<int, int> p;
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int n = servers.size(), m = tasks.size();
        if (n == 1)
        {
            vector<int> ans(m, 0);
            return ans;
        }
        priority_queue<p, vector<p>, greater<p>> pq1;
        priority_queue<p, vector<p>, greater<p>> pq2;
        for (int i = 0; i < n; ++i)
        {
            pq1.push({servers[i], i});
        }
        vector<int> ans(m);
        int curr = 0;
        for (int i = 0; i < m; ++i)
        {
            curr = max(curr, i);
            if (pq1.empty() && pq2.top().first > curr)
                curr = pq2.top().first;
            while (!pq2.empty() && pq2.top().first <= curr)
            {
                auto [t, idx] = pq2.top();
                pq2.pop();
                pq1.push({servers[idx], idx});
            }
            auto [wt, idx] = pq1.top();
            pq1.pop();
            pq2.push({curr + tasks[i], idx});
            ans[i] = idx;
        }
        return ans;
    }
};

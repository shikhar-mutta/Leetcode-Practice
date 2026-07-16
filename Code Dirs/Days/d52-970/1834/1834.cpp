// Link: https://leetcode.com/problems/single-threaded-cpu/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(nlogn) + O(nlogn) + O(nlogn) = O(nlogn)
// SC: O(n) + O(n) + O(n) = O(n)
// Approach:
//  1. Create a vector of pairs to store the tasks along with their original indices.
//  2. Sort the tasks based on their enqueue time.
//  3. Use a priority queue to process the tasks based on their processing time and original index.
//  4. Iterate through the tasks and add them to the priority queue when their enqueue time is less than or equal to the current time.
//  5. If the priority queue is empty and the current time is less than the enqueue time of the next task, update the current time to the enqueue time of the next task.
//  6. Pop the task with the smallest processing time (and smallest index in case of ties) from the priority queue, add its index to the result, and update the current time by adding the processing time of that task.
//  7. Repeat steps 4-6 until all tasks are processed and the priority queue is empty.
//  8. Return the result
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({{tasks[i][0], tasks[i][1]}, i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        long long time = 0;
        int var = 0;
        while (i < n || pq.empty() == 0)
        {
            if (pq.empty() == 1 && time < v[i].first.first)
            {
                time = v[i].first.first;
            }
            while (i < n && v[i].first.first <= time)
            {
                pq.push({v[i].first.second, v[i].second});
                i++;
            }
            ans[var++] = pq.top().second;
            time += pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
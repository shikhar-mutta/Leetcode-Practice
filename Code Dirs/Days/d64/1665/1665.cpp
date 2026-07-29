// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of tasks
// SC: O(1) constant space
//  Approach: We can sort the tasks based on the difference between the minimum energy required and the actual energy required. We can then iterate through the sorted tasks and keep track of the total energy required to complete the tasks. The maximum of the total energy required and the minimum energy required for each task will give us the minimum initial energy required to complete all tasks.
class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(),
             [](auto &a, auto &b)
             { return (a[1] - a[0]) > (b[1] - b[0]); });
        long long sum = 0, ans = 0;
        for (auto &t : tasks)
        {
            ans = max(ans, sum + t[1]);
            sum += t[0];
        }
        return (int)ans;
    }
};

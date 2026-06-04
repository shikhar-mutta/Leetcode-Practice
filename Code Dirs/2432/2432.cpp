// Link: https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: Brute Force. TC: O(n)   SC: O(1).
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int maxTime = logs[0][1], ans = logs[0][0], n = logs.size(), time;
        for (int i = 1; i < n; i++)
        {
            time = logs[i][1] - logs[i - 1][1];
            if (time > maxTime)
            {
                maxTime = time;
                ans = logs[i][0];
            }
            else if (time == maxTime)
                ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};

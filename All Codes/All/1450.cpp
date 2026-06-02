// Link: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int cnt = 0, n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                cnt++;
        }
        return cnt;
    }
};

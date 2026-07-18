// Link: https://leetcode.com/problems/teemo-attacking/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int cnt = 0, n = timeSeries.size();
        for (int i = 0; i < n; i++)
        {
            int start = timeSeries[i], end = start + duration - 1;
            i++;
            while (i < n && end >= timeSeries[i])
            {
                end = max(end, timeSeries[i] + duration - 1);
                i++;
            }
            i--;
            cnt = cnt + end - start + 1;
        }
        return cnt;
    }
};
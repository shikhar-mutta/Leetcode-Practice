// Link: https://leetcode.com/problems/button-with-longest-push-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int buttonWithLongestTime(vector<vector<int>> &events)
    {
        int n = events.size();
        int maxTime = events[0][1], ind = events[0][0];
        for (int i = 1; i < n; i++)
        {
            int duration = events[i][1] - events[i - 1][1];
            if (duration > maxTime || (duration == maxTime && events[i][0] < ind))
            {
                maxTime = duration;
                ind = events[i][0];
            }
        }
        return ind;
    }
};

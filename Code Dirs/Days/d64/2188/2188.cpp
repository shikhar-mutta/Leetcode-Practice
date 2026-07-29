// Link: https://leetcode.com/problems/minimum-time-to-finish-the-race/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 3^m)  SC: O(3^m)
//  Approach: We can use dynamic programming to solve this problem. We can represent the state of the slots using a base-3 number, where each digit represents the number of elements in that slot. We can then iterate through the elements of the array and for each element, we can try to place it in each of the slots and update the state accordingly. We can use a dp array to store the maximum AND sum for each state. Finally, we can return the maximum AND sum for the state where all elements have been placed in the slots.
class Solution
{
public:
    int d[18], dp[1001];
    int rec(int numLaps)
    {
        if (!numLaps)
            return 0;
        if (dp[numLaps] != -1)
            return dp[numLaps];
        dp[numLaps] = 2e9;
        for (int i = 0; i < 18 && d[i] != 2e9 && numLaps - 1 - i >= 0; ++i)
            dp[numLaps] = min(dp[numLaps], d[i] + rec(numLaps - 1 - i));
        return dp[numLaps];
    }
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime,
                          int numLaps)
    {
        for (int i = 0; i < 18; ++i)
            d[i] = 2e9;
        memset(dp, -1, sizeof(dp));
        for (int i = 0, j = 0; i < tires.size(); ++i, j = 0)
        {
            long long f = tires[i][0], r = tires[i][1], curr = 0, p = 1;
            while (curr + f * p < curr + changeTime + f)
            {
                curr += f * p;
                if (d[j] > curr + changeTime)
                    d[j] = curr + changeTime;
                p *= r;
                ++j;
            }
        }
        return rec(numLaps) - changeTime;
    }
};

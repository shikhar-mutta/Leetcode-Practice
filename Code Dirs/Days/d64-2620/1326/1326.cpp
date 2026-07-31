// Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: Greedy. For each tap, calculate the range it can water and store the maximum right end for each left end. Then, iterate through the garden and keep track of the farthest point that can be watered. If the current index exceeds the farthest point, it means we need to open a new tap. If we reach the end of the garden, return the number of taps opened. If we cannot reach the end, return -1.
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            maxReach[lo] = max(maxReach[lo], hi);
        }

        int taps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i > farthest)
                return -1;
            if (i > curEnd)
            {
                taps++;
                curEnd = farthest;
            }
            farthest = max(farthest, maxReach[i]);
        }
        return taps;
    }
};

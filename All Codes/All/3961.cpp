// Link: https://leetcode.com/problems/maximize-sum-of-device-ratings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) SC: O(1)
//  Approach: For each device, find the two smallest unit ratings. The maximum sum of device ratings is the sum of the second smallest ratings of all devices, minus the smallest of those second smallest ratings, plus the smallest of the smallest ratings across all devices. This accounts for the fact that we can remove one unit from one device to maximize the overall sum.
//  The logic is that we want to keep the second smallest rating from each device, but we can replace the smallest of those second smallest ratings with the smallest of the smallest ratings across all devices to maximize the sum.
using ll = long long;
class Solution
{
public:
    long long maxRatings(vector<vector<int>> &units)
    {
        int m = units.size(), n = units[0].size();

        if (n == 1)
        { // shedding the only unit empties the device
            ll s = 0;
            for (int i = 0; i < m; i++)
                s += units[i][0];
            return s;
        }

        ll sumSecond = 0;
        int minFirst = INT_MAX, minSecond = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            int m1 = INT_MAX, m2 = INT_MAX; // two smallest, WITH multiplicity
            for (int j = 0; j < n; j++)
            {
                int v = units[i][j];
                if (v < m1)
                {
                    m2 = m1;
                    m1 = v;
                }
                else if (v < m2)
                {
                    m2 = v;
                }
            }
            sumSecond += m2;
            minFirst = min(minFirst, m1);
            minSecond = min(minSecond, m2);
        }
        return sumSecond - minSecond + minFirst;
    }
};
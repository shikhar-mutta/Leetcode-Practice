// Link: https://leetcode.com/problems/heaters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(mlogm) + O(nlogm) = O(nlogn + mlogm). SC: O(1)
    //  Approach: Sort the heaters. For each house, find the nearest heater using binary search.
    //  The radius is the maximum distance between a house and its nearest heater.
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(heaters.begin(), heaters.end());
        long long radius = 0;
        for (int h : houses)
        {
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            long long nearest = LLONG_MAX;
            if (it != heaters.end())
                nearest = (long long)*it - h;
            if (it != heaters.begin())
                nearest = min(nearest, (long long)h - *prev(it));
            radius = max(radius, nearest);
        }
        return radius;
    }
};

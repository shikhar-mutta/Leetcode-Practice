// Link: https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(1)
//    Approach:
//    1. We can use binary search to find the minimum time required to complete the totalTrips.
//    2. We can check if the mid time is sufficient to complete the totalTrips by iterating through the time array and calculating the number of trips that can be completed in mid time.
//    3. If the number of trips is greater than or equal to totalTrips, we can update the right pointer to mid - 1, else we can update the left pointer to mid + 1.
//    4. We can return the left pointer as the minimum time required to complete the totalTrips.
class Solution
{
public:
    bool check(vector<int> &time, int totalTrips, long long mid)
    {
        long long tracker = 0;
        for (int hour : time)
        {
            tracker += mid / hour;

            if (tracker >= totalTrips)
            {
                return true;
            }
        }
        return false;
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 1;
        long long minimumHour = *min_element(time.begin(), time.end());
        long long right = minimumHour * totalTrips;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (check(time, totalTrips, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogm) where n is the length of the dist vector and m is the maximum speed
// SC: O(1)
//   Approach: Binary Search
//      1. If the hour is less than or equal to the number of dist, return -1.
//      2. Calculate the minimum speed and maximum speed.
//      3. While the minimum speed is less than the maximum speed, calculate the speed between the minimum and maximum speed.
//      4. Calculate the time taken to travel the distance at the speed between the minimum and maximum speed.
//      5. If the time taken is equal to the hour, return the speed between the minimum and maximum speed.
//      6. If the time taken is greater than the hour, set the minimum speed to the speed between the minimum and maximum speed
//      7. If the time taken is less than the hour, set the maximum speed to the speed between the minimum and maximum speed
//      8. If the maximum speed minus the minimum speed is equal to 1, return the maximum speed.
class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (hour <= (double)(dist.size() - 1))
        {
            return -1;
        }
        double sum = 0;
        for (int i : dist)
        {
            sum += (double)i;
        }
        double min = floor(sum / hour);
        double mintime = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            mintime += dist[i] / ((double)min);
            if (i != dist.size() - 1)
            {
                mintime = ceil(mintime);
            }
        }

        if (mintime == hour)
        {
            return min;
        }

        double max = ceil(sum / (hour - (double)(dist.size() - 1)));
        while (min < max)
        {
            double between = floor((max - min) / 2 + min);
            double time = 0;
            for (int i = 0; i < dist.size(); i++)
            {
                time += dist[i] / ((double)between);
                if (i != dist.size() - 1)
                {
                    time = ceil(time);
                }
            }

            if (time == hour)
            {
                return between;
            }
            else if (time > hour)
            {
                // too slow
                min = between;
            }
            else if (time < hour)
            {
                // too fast
                max = between;
            }
            if (max - min == 1.0)
            {
                return max;
            }
        }
        return max;
    }
};
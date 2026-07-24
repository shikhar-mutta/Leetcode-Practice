// Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    // Approach:
    //  1. Calculate the angle of the minute hand from 12 o'clock position. The minute hand moves 6 degrees for every minute (360 degrees / 60 minutes).
    //  2. Calculate the angle of the hour hand from 12 o'clock position. The hour hand moves 30 degrees for every hour (360 degrees / 12 hours) and also moves 0.5 degrees for every minute (30 degrees / 60 minutes).
    //  3. Calculate the absolute difference between the two angles.
    //  4. Return the minimum of the absolute difference and 360 degrees minus the absolute difference, as the angle between the hands can be measured in either direction.
    //  5. Return the minimum angle.
    double angleClock(int hour, int minutes)
    {
        double minAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double diff = fabs(hourAngle - minAngle);
        return min(diff, 360.0 - diff);
    }
};
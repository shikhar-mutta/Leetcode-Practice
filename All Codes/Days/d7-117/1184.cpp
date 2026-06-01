// Link: https://leetcode.com/problems/distance-between-bus-stops/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int n = distance.size();
        int clockwiseDist = 0;

        // Calculate the clockwise distance from start to destination
        for (int i = start; i != destination; i = (i + 1) % n)
        {
            clockwiseDist += distance[i];
        }

        // Calculate the total distance around the circle
        int totalDist = accumulate(distance.begin(), distance.end(), 0);

        // The counterclockwise distance is the total distance minus the clockwise distance
        int counterClockwiseDist = totalDist - clockwiseDist;

        // Return the minimum of the two distances
        return min(clockwiseDist, counterClockwiseDist);
    }
};

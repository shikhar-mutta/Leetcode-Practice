// Link: https://leetcode.com/problems/nearest-available-drone/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestDrone(vector<vector<int>> &drones, vector<int> &target)
    {
        int tx = target[0], ty = target[1];
        int bestIdx = -1;
        long long bestDist = LLONG_MAX;

        for (int i = 0; i < (int)drones.size(); i++)
        {
            long long x = drones[i][0];
            long long y = drones[i][1];
            long long range = drones[i][2];
            // Calculate the Manhattan distance from the drone to the target
            long long dist = abs(x - tx) + abs(y - ty);
            // Check if the drone is within range and if it's the closest one found so far
            if (dist <= range && dist < bestDist)
            {
                bestDist = dist;
                bestIdx = i;
            }
        }

        return bestIdx;
    }
};
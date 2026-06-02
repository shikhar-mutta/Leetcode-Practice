// Link: https://leetcode.com/problems/find-the-highest-altitude/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0;     // To keep track of the highest altitude
        int currentAltitude = 0; // To keep track of the current altitude

        for (int g : gain)
        {
            currentAltitude += g;                            // Update the current altitude by adding the gain
            maxAltitude = max(maxAltitude, currentAltitude); // Update the maximum altitude if the current is higher
        }

        return maxAltitude; // Return the highest altitude reached
    }
};

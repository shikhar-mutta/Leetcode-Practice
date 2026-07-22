// Link: https://leetcode.com/problems/self-crossing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input vector distance. We iterate through the vector once to check for self-crossing conditions.
    // SC: O(1) as we use a constant amount of space to store the input vector distance and the result of the self-crossing check.
    // Approach:
    //  1. We can iterate through the vector distance starting from the 4th element (index 3) and check for the three possible cases of self-crossing.
   
    bool isSelfCrossing(vector<int> &distance)
    {
        int n = distance.size();

        if (n <= 3)
            return false;

        for (int i = 3; i < n; i++)
        {
            // Case 1: 4th line crosses 1st line
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
            {
                return true;
            }

            // Case 2: 5th line meets 1st line
            if (i >= 4 && distance[i - 1] == distance[i - 3] &&
                distance[i] + distance[i - 4] >= distance[i - 2])
            {
                return true;
            }

            // Case 3: 6th line crosses 1st line
            if (i >= 5 && distance[i - 2] >= distance[i - 4] &&
                distance[i - 1] <= distance[i - 3] &&
                distance[i - 1] + distance[i - 5] >= distance[i - 3] &&
                distance[i] + distance[i - 4] >= distance[i - 2])
            {
                return true;
            }
        }

        return false;
    }
};

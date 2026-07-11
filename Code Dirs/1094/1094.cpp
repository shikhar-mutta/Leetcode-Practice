// Link: https://leetcode.com/problems/car-pooling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach: Use a difference array to keep track of the number of passengers getting on and off the car at each stop. Iterate through the difference array to check if the number of passengers onboard exceeds the capacity at any point.
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int diff[1001] = {};
        for (auto &t : trips)
        {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }
        int onboard = 0;
        for (int i = 0; i <= 1000; i++)
        {
            onboard += diff[i];
            if (onboard > capacity)
                return false;
        }
        return true;
    }
};

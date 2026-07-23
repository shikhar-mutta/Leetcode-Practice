// Link: https://leetcode.com/problems/corporate-flight-bookings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) where n is the number of flights and m is the number of bookings
// SC: O(n) where n is the number of flights
// Approach:
//  1. We will use a difference array to keep track of the number of seats booked for each flight.
//  2. For each booking, we will update the difference array by adding the number of seats booked to the start index and subtracting the number of seats booked from the end index
//  3. Finally, we will calculate the prefix sum of the difference array to get the number of seats booked for each flight and return the result.
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n + 1, 0);
        for (auto &b : bookings)
        {
            diff[b[0] - 1] += b[2];
            diff[b[1]] -= b[2];
        }

        vector<int> result(n);
        int running = 0;
        for (int i = 0; i < n; i++)
        {
            running += diff[i];
            result[i] = running;
        }
        return result;
    }
};

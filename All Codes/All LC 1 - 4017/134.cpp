// Link: https://leetcode.com/problems/gas-station/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of gas stations. We iterate through the gas and cost arrays once to calculate the total gas and tank values.
    // SC: O(1) as we are using a constant amount of extra space for the variables total, tank, and start, regardless of the input size.
    // Approach:
    // 1. We maintain three variables: total, tank, and start.
    //    - total keeps track of the overall difference between gas and cost across all stations.
    //    - tank keeps track of the current amount of gas in the tank as we iterate through the stations.
    //    - start keeps track of the index of the potential starting gas station.
    // 2. We iterate through each gas station, calculating the difference between gas[i] and cost[i].
    //    - We add this difference to both total and tank.
    //    - If tank becomes negative, it means we cannot reach the next station from the current starting station, so we update start to the next station (i + 1) and reset tank to 0.
    // 3. After iterating through all stations, if total is negative, it means that the total gas is less than the total cost, and it's impossible to complete the circuit, so we return -1. Otherwise, we return the index of the starting gas station.
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < (int)gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

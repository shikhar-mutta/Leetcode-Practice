// Link: https://leetcode.com/problems/design-underground-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for each operation, SC: O(n) where n is the number of unique customers and stations
// Approach:
//  1. We maintain a checkInMap to store the check-in information of each customer, where the key is the customer ID and the value is a pair containing the station name and check-in time.
//  2. We also maintain a travelTimes map to store the total travel time and count of trips between each pair of stations, where the key is the start station and the value is another map with the end station as the key and a pair containing the total travel time and count of trips as the value.
//  3. When a customer checks in, we store their check-in information in the checkInMap.
//  4. When a customer checks out, we retrieve their check-in information from the checkInMap, calculate the travel time, and update the travelTimes map accordingly.
class UndergroundSystem
{
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, unordered_map<string, pair<double, int>>> travelTimes;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto it = checkInMap.find(id);
        auto &[startStation, startTime] = it->second;

        auto &[totalTime, count] = travelTimes[startStation][stationName];
        totalTime += t - startTime;
        count++;

        checkInMap.erase(it);
    }

    double getAverageTime(string startStation, string endStation)
    {
        auto &[totalTime, count] = travelTimes[startStation][endStation];
        return totalTime / count;
    }
};

// Link: https://leetcode.com/problems/design-underground-system/description/

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> checkins;
    unordered_map<string, pair<double,int>> stats; // key: "start->end"

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkins[id];
        string key = startStation + "->" + stationName;
        stats[key].first += (t - startTime);
        stats[key].second += 1;
        checkins.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "->" + endStation;
        auto& [total, count] = stats[key];
        return total / count;
    }
};

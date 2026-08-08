// Link: https://leetcode.com/problems/distance-between-bus-stops/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int total = accumulate(distance.begin(), distance.end(), 0);
        int clockwise = 0;
        for (int i = start; i < destination; i++) clockwise += distance[i];
        return min(clockwise, total - clockwise);
    }
};

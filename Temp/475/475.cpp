// Link: https://leetcode.com/problems/heaters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((h+n) log n)  SC: O(1)
// Approach: sort heaters, for each house binary search the nearest heater
// (checking both the lower_bound position and the one before it), track
// the max of these minimum distances
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int h : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            long long dist = LLONG_MAX;
            if (it != heaters.end()) dist = min(dist, (long long)abs(*it - h));
            if (it != heaters.begin()) dist = min(dist, (long long)abs(*prev(it) - h));
            radius = max(radius, (int)dist);
        }
        return radius;
    }
};

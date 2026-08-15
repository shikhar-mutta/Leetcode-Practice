// Link: https://leetcode.com/problems/watering-plants/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int water = capacity;
        int steps = 0;
        for (int i = 0; i < n; i++) {
            if (water < plants[i]) {
                steps += 2 * i;
                water = capacity;
            }
            water -= plants[i];
            steps += 1;
        }
        return steps;
    }
};

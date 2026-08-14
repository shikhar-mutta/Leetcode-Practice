// Link: https://leetcode.com/problems/watering-plants-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = (int)plants.size() - 1;
        int waterA = capacityA, waterB = capacityB;
        int refills = 0;
        while (i < j) {
            if (waterA < plants[i]) { refills++; waterA = capacityA; }
            waterA -= plants[i];
            if (waterB < plants[j]) { refills++; waterB = capacityB; }
            waterB -= plants[j];
            i++; j--;
        }
        if (i == j) {
            if (max(waterA, waterB) < plants[i]) refills++;
        }
        return refills;
    }
};

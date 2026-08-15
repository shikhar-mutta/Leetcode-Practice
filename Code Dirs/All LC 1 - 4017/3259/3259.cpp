// Link: https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<long long> dpA(n), dpB(n);
        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            long long prevA2 = (i >= 2) ? dpB[i-2] : 0;
            long long prevB2 = (i >= 2) ? dpA[i-2] : 0;
            dpA[i] = energyDrinkA[i] + max(dpA[i-1], prevA2);
            dpB[i] = energyDrinkB[i] + max(dpB[i-1], prevB2);
        }
        return max(dpA[n-1], dpB[n-1]);
    }
};

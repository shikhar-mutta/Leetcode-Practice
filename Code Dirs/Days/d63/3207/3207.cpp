// Link: https://leetcode.com/problems/maximum-points-after-enemy-battles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: If currentEnergy can't even beat the weakest enemy, no points
// are possible. Otherwise, the optimal strategy nets currentEnergy plus the
// sum of all enemy energies except one (used purely to farm points via
// repeated defeat/mark-undefeated cycles against the weakest enemy), so the
// total usable energy divided by the weakest enemy's cost gives max points.
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n = enemyEnergies.size();
        int weakest = INT_MAX;
        long long totalEnergies = currentEnergy;
        for(int i = 0; i < n; i++){
            weakest = min(weakest, enemyEnergies[i]);
            totalEnergies += enemyEnergies[i];
        }
        if(currentEnergy < weakest) return 0;
        totalEnergies -= weakest;
        return totalEnergies/weakest;
    }
};

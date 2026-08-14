// Link: https://leetcode.com/problems/maximum-points-after-enemy-battles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        long long cheapest = enemyEnergies[0];
        if (currentEnergy < cheapest) return 0;

        long long points = 1;
        long long energy = currentEnergy - cheapest;
        for (int i = 1; i < (int)enemyEnergies.size(); i++) energy += enemyEnergies[i];
        points += energy / cheapest;
        return points;
    }
};

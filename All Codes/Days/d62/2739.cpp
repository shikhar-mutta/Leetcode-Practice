// Link: https://leetcode.com/problems/total-distance-traveled/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(mainTank)
// SC: O(1)
// Approach: simulate 5-liter burns from the main tank one at a time; whenever
// the additional tank has fuel, transfer 1 liter into the main tank (net -4
// instead of -5) after each burn. Each 5-liter burn covers 50 units; leftover
// mainTank fuel below 5 still covers 10 units per liter.
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int travelledD = 0;
        while (mainTank >= 5) {
            if (additionalTank > 0) {
                mainTank -= 4;
                additionalTank--;
            } else {
                mainTank -= 5;
            }
            travelledD += 50;
        }
        return travelledD += mainTank * 10;
    }
};

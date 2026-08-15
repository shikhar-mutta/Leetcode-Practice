// Link: https://leetcode.com/problems/total-distance-traveled/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            distance += 50;
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        distance += mainTank * 10;
        return distance;
    }
};

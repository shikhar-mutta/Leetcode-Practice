// Link: https://leetcode.com/problems/calculate-delayed-arrival-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

// Link: https://leetcode.com/problems/calculate-delayed-arrival-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: add the delay to the arrival time and wrap around the
// 24-hour clock with modulo.
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

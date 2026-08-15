// Link: https://leetcode.com/problems/design-parking-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach:
//   1. We will maintain an array of size 4 to store the number of slots available for each type of car.
//   2. When a car is added, we will check if there is a slot available for that type of car and decrement the count of slots available for that type of car.
class ParkingSystem
{
    int slots[4];

public:
    ParkingSystem(int big, int medium, int small)
    {
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }

    bool addCar(int carType) { return slots[carType]-- > 0; }
};
// Link: https://leetcode.com/problems/design-parking-system/description/

#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
public:
    int slots[4];

    ParkingSystem(int big, int medium, int small) {
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }

    bool addCar(int carType) {
        if (slots[carType] > 0) {
            slots[carType]--;
            return true;
        }
        return false;
    }
};

// Link: https://leetcode.com/problems/water-bottles-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles, empty = numBottles, rate = numExchange;
        while (empty >= rate) {
            empty -= rate;
            rate++;
            empty++;
            drunk++;
        }
        return drunk;
    }
};

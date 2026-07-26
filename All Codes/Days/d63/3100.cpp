// Link: https://leetcode.com/problems/water-bottles-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(numBottles)), SC: O(1)
// Approach: Simulate directly: while enough empties exist for the current
// exchange rate, trade them in, drink the new bottle (it becomes empty
// again), and bump the exchange rate by 1 as the rules require.
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            empty -= numExchange;
            numExchange++;
            totalDrunk++;
            empty++; // gained one full bottle, drink it -> becomes empty again
        }

        return totalDrunk;
    }
};

// Link: https://leetcode.com/problems/water-bottles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(numBottles)), SC: O(1)
    //  Approach:
    //  1. Initialize total as numBottles and empty as numBottles
    //  2. While empty is greater than or equal to numExchange, calculate the number of new bottles that can be obtained by exchanging empty bottles (refill = empty / numExchange).
    //  3. Add refill to total and update empty as the sum of remaining empty bottles (empty % numExchange) and the newly obtained bottles (refill).
    //  4. Return total as the final result.
    int numWaterBottles(int numBottles, int numExchange)
    {
        int total = numBottles, empty = numBottles;
        while (empty >= numExchange)
        {
            int refill = empty / numExchange;
            total += refill;
            empty = empty % numExchange + refill;
        }
        return total;
    }
};
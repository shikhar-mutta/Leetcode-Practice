// Link: https://leetcode.com/problems/watering-plants-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach:
//  1. We will use two pointers, one starting from the beginning of the array and the other from the end.
//  2. We will keep track of the remaining water in both Alice and Bob's watering cans.
//  3. If either Alice or Bob doesn't have enough water to water the current plant,
//     we will refill their watering can and increment the refill count.
//  4. We will continue this process until both pointers meet in the middle of the array.
class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int i = 0, j = n - 1;
        int a = capacityA, b = capacityB, refills = 0;

        while (i < j)
        {
            if (a < plants[i])
            {
                ++refills;
                a = capacityA;
            }
            a -= plants[i];
            ++i;

            if (b < plants[j])
            {
                ++refills;
                b = capacityB;
            }
            b -= plants[j];
            --j;
        }

        if (i == j)
        {
            if (max(a, b) < plants[i])
                ++refills;
        }
        return refills;
    }
};

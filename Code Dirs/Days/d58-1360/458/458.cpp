// Link: https://leetcode.com/problems/poor-pigs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(buckets) / log(rounds + 1)) where rounds = minutesToTest / minutesToDie
    // SC: O(1)
    // Approach:
    // 1. Calculate the number of rounds we can perform based on the given time constraints
    // 2. Each pig can be in one of (rounds + 1) states (alive or dead in each round)
    // 3. The total number of combinations of states for all pigs is (rounds + 1)^pigs
    // 4. We need to find the minimum number of pigs such that (rounds + 1)^pigs >= buckets
    // 5. We can use a loop to increment the number of pigs until the condition is satisfied.
    // 6. Return the minimum number of pigs required to determine the poisoned bucket.
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int rounds = minutesToTest / minutesToDie;
        int base = rounds + 1;
        int pigs = 0;
        long long combos = 1;
        while (combos < buckets)
        {
            combos *= base;
            pigs++;
        }
        return pigs;
    }
};

// Link: https://leetcode.com/problems/poor-pigs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: each pig can be in one of (rounds+1) states over the test
// duration (which round it died in, or survived); need (rounds+1)^pigs >= buckets
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        int states = rounds + 1;
        int pigs = 0;
        long long capacity = 1;
        while (capacity < buckets) {
            capacity *= states;
            pigs++;
        }
        return pigs;
    }
};

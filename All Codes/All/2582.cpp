// Link: https://leetcode.com/problems/pass-the-pillow/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: the pillow bounces back and forth in a period of 2*(n-1) passes.
// Reduce time mod that period to get position within one round trip, then
// person = cycle+1 on the forward leg, or mirrored back down on the return leg.
class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = time % (2 * (n - 1)); // position within one full round trip
        if (cycle < n - 1)
            return cycle + 1; // forward leg: person 1, 2, ..., n
        else
            return 2 * (n - 1) - cycle + 1; // backward leg: person n-1, ..., 1
    }
};

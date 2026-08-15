// Link: https://leetcode.com/problems/bulb-switcher/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: a bulb ends on iff it has an odd number of divisors, which
// happens only for perfect squares; count = floor(sqrt(n))
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt((double)n);
    }
};

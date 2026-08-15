// Link: https://leetcode.com/problems/power-of-three/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: 3^19 is the largest power of 3 fitting in int; n is a power of 3
// iff it divides that value evenly
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

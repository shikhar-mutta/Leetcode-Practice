// Link: https://leetcode.com/problems/number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(popcount)  SC: O(1)
// Approach: Brian Kernighan's trick — n & (n-1) clears the lowest set bit, count iterations until 0
class Solution {
public:
    int hammingWeight(int n) {
        uint32_t x = (uint32_t)n;
        int count = 0;
        while (x) { x &= (x - 1); count++; }
        return count;
    }
};

// Link: https://leetcode.com/problems/reverse-bits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(32)  SC: O(1)
// Approach: shift result left, OR in the lowest bit of n, shift n right, repeat 32 times
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

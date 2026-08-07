// Link: https://leetcode.com/problems/number-complement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: build a mask of all 1s matching num's bit length, XOR with it
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask ^ num;
    }
};

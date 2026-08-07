// Link: https://leetcode.com/problems/hamming-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: popcount of XOR
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};

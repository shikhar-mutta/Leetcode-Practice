// Link: https://leetcode.com/problems/hamming-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        // differing bits = set bits in x XOR y
        return __builtin_popcount(x ^ y);
    }
};

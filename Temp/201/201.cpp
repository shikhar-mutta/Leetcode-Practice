// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: the AND of the whole range collapses to the common prefix of left and right's binary
// representations; right-shift both until equal, then shift back
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};

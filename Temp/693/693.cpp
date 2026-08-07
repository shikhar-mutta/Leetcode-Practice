// Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: XOR n with itself shifted right by 1; if bits alternate, the result is all 1s (a number of the form 2^k - 1), checked via (x & (x+1)) == 0.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n ^ (n >> 1);
        return (x & (x+1)) == 0;
    }
};

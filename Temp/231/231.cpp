// Link: https://leetcode.com/problems/power-of-two/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: a power of two has exactly one set bit; n & (n-1) clears the lowest set bit, so it becomes 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

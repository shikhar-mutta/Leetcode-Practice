// Link: https://leetcode.com/problems/smallest-even-multiple/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: the smallest number divisible by both 2 and n is their LCM. If
// n is already even, n itself works; otherwise 2*n is the smallest even
// multiple.
class Solution {
public:
    int smallestEvenMultiple(int n) { return n % 2 == 0 ? n : 2 * n; }
};

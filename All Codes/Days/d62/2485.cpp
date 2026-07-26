// Link: https://leetcode.com/problems/find-the-pivot-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (ignoring sqrt's cost)
// SC: O(1)
// Approach: pivot x satisfies 1+...+x == x+...+n, which algebraically
// reduces to x^2 == n(n+1)/2. So compute total = n(n+1)/2, take its
// integer square root, and check whether squaring it recovers total
// exactly; if so that's the pivot, otherwise no pivot exists.
class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2; // sum 1..n
        int x = (int)sqrt((double)total);
        return (x * x == total) ? x : -1;
    }
};

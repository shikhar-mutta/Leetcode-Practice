// Link: https://leetcode.com/problems/sqrtx/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log x)  SC: O(1)
// Approach: binary search for the largest integer whose square <= x, using long long to avoid overflow
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            if (mid * mid <= x) l = mid;
            else r = mid - 1;
        }
        return (int)l;
    }
};

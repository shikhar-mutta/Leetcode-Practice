// Link: https://leetcode.com/problems/water-and-jug-problem/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(x,y)))  SC: O(1)
// Approach: reachable amounts are exactly multiples of gcd(x,y) up to x+y
// (Bezout's identity)
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (x == 0 || y == 0) return target == 0 || target == x + y;
        return target % gcd(x, y) == 0;
    }
};

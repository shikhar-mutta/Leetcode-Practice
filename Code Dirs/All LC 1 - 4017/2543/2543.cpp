// Link: https://leetcode.com/problems/check-if-point-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int g = gcd(targetX, targetY);
        while (g % 2 == 0) g /= 2;
        return g == 1;
    }
};

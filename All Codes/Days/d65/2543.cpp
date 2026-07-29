// Link: https://leetcode.com/problems/check-if-point-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(X,Y))), SC: O(1)
// Approach: moves preserve gcd up to factors of 2 (working backward, halving an even coordinate
// or subtracting the smaller from the larger — like a gcd reduction). Reachable from (1,1) iff
// gcd(X,Y) reduced of all factors of 2 equals 1, i.e. gcd(X,Y) is a power of two.
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int g = gcd(targetX, targetY);
        return (g & (g - 1)) == 0;
    }
};

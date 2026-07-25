// Link: https://leetcode.com/problems/find-the-maximum-achievable-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: each operation increases num by 1 and, to keep it "achievable"
// against x under one +1/-1 per side, x must increase by 2 relative to num
// per op (num moves toward x by 1, x moves away by 1). After t ops the
// maximum reachable x is num + 2*t.
class Solution {
public:
    int theMaximumAchievableX(int num, int t) { return num + 2 * t; }
};

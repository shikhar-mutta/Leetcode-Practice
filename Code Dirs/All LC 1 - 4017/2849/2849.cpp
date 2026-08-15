// Link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx), dy = abs(sy - fy);
        int minMoves = max(dx, dy);
        if (minMoves == 0) return t != 1;
        return t >= minMoves;
    }
};

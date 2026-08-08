// Link: https://leetcode.com/problems/reaching-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(max(tx,ty))) SC: O(1)
// Approach: work backwards from (tx,ty) toward (sx,sy); while tx>sx and ty>sy, use modulo to skip many steps at once (since the larger coordinate reduces by the smaller repeatedly); handle the boundary case where one coordinate already equals its source.
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        if (tx == sx && ty >= sy) return (ty - sy) % sx == 0;
        if (ty == sy && tx >= sx) return (tx - sx) % sy == 0;
        return false;
    }
};

// Link: https://leetcode.com/problems/reaching-points/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(max(tx,ty)))  SC: O(1)
// Approach: work backwards from (tx,ty) toward (sx,sy): while both
// coordinates exceed the start, reduce the larger one modulo the
// smaller (equivalent to repeatedly subtracting, since (a+b,b)->(a,b)
// reversed many times at once). Once one coordinate matches its start
// value, check if the other can be reached by subtracting multiples of
// the fixed coordinate.
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        if (tx == sx) return ty >= sy && (ty - sy) % sx == 0;
        if (ty == sy) return tx >= sx && (tx - sx) % sy == 0;
        return false;
    }
};

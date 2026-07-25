// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log target)
// SC: O(1)
// Approach: work backwards from target toward 1, greedily halving whenever
// possible (always optimal, since a double is a "free" 2x reduction versus
// paying 1 move per unit) as long as doublings remain and the value is
// even; if it's odd, spend a move decrementing to make it halvable. Once
// doublings run out, the remaining distance to 1 must be closed one
// decrement at a time, so add it in one shot.
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target > 1) {
            if (maxDoubles > 0 && target % 2 == 0) {
                target /= 2;
                --maxDoubles;
            } else if (maxDoubles > 0) {
                --target; // make it even for the next halving
            } else {
                moves += target - 1; // no doublings left: decrement all the way
                break;
            }
            ++moves;
        }
        return moves;
    }
};

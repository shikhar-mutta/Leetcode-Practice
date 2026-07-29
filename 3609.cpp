// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        long long X = tx, Y = ty, SX = sx, SY = sy;
        long long moves = 0;

        while (true) {
            if (X == SX && Y == SY) return (int)moves;
            if (X < SX || Y < SY) return -1;
            if (X < 0 || Y < 0) return -1;

            if (X >= Y) {
                if (Y == 0 || X >= 2 * Y) {
                    if (X % 2 != 0) return -1;
                    X /= 2;
                } else {
                    X -= Y;
                }
            } else {
                if (X == 0 || Y >= 2 * X) {
                    if (Y % 2 != 0) return -1;
                    Y /= 2;
                } else {
                    Y -= X;
                }
            }
            moves++;
            if (moves > 200) return -1; // safety cap, should never trigger for valid range
        }
    }
};

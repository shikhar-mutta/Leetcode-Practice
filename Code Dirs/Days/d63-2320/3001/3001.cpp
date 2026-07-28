// Link: https://leetcode.com/problems/minimum-moves-to-capture-the-queen/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: check whether the rook has a clear line to the queen (same row
// or column, with the bishop not sitting strictly between them) or the
// bishop has a clear diagonal to the queen (same diagonal, with the rook not
// sitting strictly between them, verified by checking the rook is collinear
// with both via matching diagonal offsets). Either clear line means capture
// in 1 move; otherwise 2 moves always suffice.
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        bool clearRook = false;
        if (a == e) {
            clearRook = true;
            if (c == e) {
                int lo = min(b, f), hi = max(b, f);
                if (d > lo && d < hi) clearRook = false;
            }
        } else if (b == f) {
            clearRook = true;
            if (d == f) {
                int lo = min(a, e), hi = max(a, e);
                if (c > lo && c < hi) clearRook = false;
            }
        }

        bool clearBishop = false;
        if (abs(c - e) == abs(d - f)) {
            clearBishop = true;
            if (abs(a - c) == abs(b - d) && abs(a - e) == abs(b - f)) {
                int lo = min(c, e), hi = max(c, e);
                if (a > lo && a < hi) clearBishop = false;
            }
        }

        return (clearRook || clearBishop) ? 1 : 2;
    }
};

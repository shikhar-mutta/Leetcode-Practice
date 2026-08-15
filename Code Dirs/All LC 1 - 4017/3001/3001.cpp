// Link: https://leetcode.com/problems/minimum-moves-to-capture-the-queen/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // rook (a,b) captures in 1 move
        if (a == e) {
            int lo = min(b, f), hi = max(b, f);
            if (!(c == a && d > lo && d < hi)) return 1;
        }
        if (b == f) {
            int lo = min(a, e), hi = max(a, e);
            if (!(d == b && c > lo && c < hi)) return 1;
        }
        // bishop (c,d) captures in 1 move
        if (abs(c - e) == abs(d - f)) {
            int dx = (e > c) ? 1 : -1;
            int dy = (f > d) ? 1 : -1;
            bool blocked = false;
            int x = c + dx, y = d + dy;
            while (x != e) {
                if (x == a && y == b) { blocked = true; break; }
                x += dx; y += dy;
            }
            if (!blocked) return 1;
        }
        return 2;
    }
};

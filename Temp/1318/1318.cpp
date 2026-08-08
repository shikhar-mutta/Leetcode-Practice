// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            int ba = (a >> i) & 1, bb = (b >> i) & 1, bc = (c >> i) & 1;
            if (bc == 1) {
                if (ba == 0 && bb == 0) flips++;
            } else {
                flips += ba + bb;
            }
        }
        return flips;
    }
};

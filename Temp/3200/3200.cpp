// Link: https://leetcode.com/problems/maximum-height-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int simulate(int a, int b) {
        int height = 0;
        for (int row = 1; ; row++) {
            if (row % 2 == 1) {
                if (a < row) break;
                a -= row;
            } else {
                if (b < row) break;
                b -= row;
            }
            height++;
        }
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(simulate(red, blue), simulate(blue, red));
    }
};

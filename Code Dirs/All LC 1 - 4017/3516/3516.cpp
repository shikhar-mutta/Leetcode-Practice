// Link: https://leetcode.com/problems/find-closest-person/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z), dy = abs(y - z);
        if (dx < dy) return 1;
        if (dy < dx) return 2;
        return 0;
    }
};

// Link: https://leetcode.com/problems/construct-the-longest-new-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int minXY = min(x, y);
        int extra = (x != y) ? 1 : 0;
        return (minXY * 2 + z + extra) * 2;
    }
};

// Link: https://leetcode.com/problems/moving-stones-until-consecutive/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a,b,c}), z = max({a,b,c}), y = a+b+c-x-z;
        int minMoves;
        if (y - x == 1 && z - y == 1) minMoves = 0;
        else if (y - x <= 2 || z - y <= 2) minMoves = 1;
        else minMoves = 2;
        int maxMoves = (y - x - 1) + (z - y - 1);
        return {minMoves, maxMoves};
    }
};

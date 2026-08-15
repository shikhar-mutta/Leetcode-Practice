// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 1) {
                target--;
            } else {
                target /= 2;
                maxDoubles--;
            }
            moves++;
        }
        return moves + (target - 1);
    }
};

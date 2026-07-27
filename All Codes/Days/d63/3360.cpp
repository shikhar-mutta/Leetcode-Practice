// Link: https://leetcode.com/problems/stone-removal-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) SC: O(1)
// Approach: simulate turns removing 10, 9, 8, ... stones alternately;
// the player unable to remove the required amount loses. Alice moves first.
class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 10;
        bool aliceTurn = true;
        while (n >= turn) {
            n -= turn;
            turn--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};

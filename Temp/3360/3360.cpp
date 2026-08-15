// Link: https://leetcode.com/problems/stone-removal-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool aliceTurn = true;
        while (n >= remove) {
            n -= remove;
            remove--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};

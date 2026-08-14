// Link: https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        bool alice = true;
        while (x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            alice = !alice;
        }
        return alice ? "Bob" : "Alice";
    }
};

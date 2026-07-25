// Link: https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: each round consumes 1 coin of type x and 4 coins of type y, so
// the number of full rounds playable is R = min(x, y/4). Players alternate
// starting with Alice, and whoever can't move loses, so Alice made the last
// move (and wins) iff R is odd.
class Solution {
public:
    string winningPlayer(int x, int y) {
        return min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
};

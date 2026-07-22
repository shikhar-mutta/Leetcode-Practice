// Link: https://leetcode.com/problems/nim-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) where n is the input integer. We perform a constant-time operation to check if n is divisible by 4.
    // SC: O(1) as we use a constant amount of space to store the input integer n and the result of the modulo operation.
    // Approach:
    //  1. We can use a mathematical observation to solve this problem.
    //  2. If the number of stones n is divisible by 4, then the player who starts the game will lose if both players play optimally. This is because the first player can only take 1, 2, or 3 stones, leaving a multiple of 4 for the second player, who can then always take stones to leave another multiple of 4 for the first player. This cycle continues until the first player is forced to take the last stone and lose the game.
    //  3. If n is not divisible by 4, then the first player can always take a number of stones that leaves a multiple of 4 for the second player, ensuring that the first player can win the game.
    //  4. Therefore, we can simply check if n is divisible by 4 to determine if the first player can win the game.
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};

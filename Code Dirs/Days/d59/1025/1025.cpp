// Link: https://leetcode.com/problems/divisor-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) SC: O(1)
    // Approach: Math
    //  1. If n is even, Alice can always win by choosing 1 as her first move, which will leave Bob with an odd number. From there, Alice can always choose a divisor of the current number that is even, leaving Bob with an odd number again. This process continues until Bob is left with 1, at which point he loses.
    //  2. If n is odd, Alice will lose because any divisor of an odd number is also odd, and thus she will leave Bob with an even number. Bob can then follow the same strategy as above, eventually leaving Alice with 1 and winning the game.
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};

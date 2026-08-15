// Link: https://leetcode.com/problems/chalkboard-xor-game/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: classic result — if the XOR of all numbers is already 0,
// the current player wins immediately (any erasure keeps a non-zero
// XOR that the opponent must eventually reduce to 0, forcing them to
// lose... actually the starting XOR being 0 means the player who is
// about to move already faces a winning board). Otherwise, the first
// player wins iff the array has an even length (they can always mirror
// a strategy that eventually zeroes the board on the opponent's turn).
class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        int x = 0;
        for (int v : nums)
            x ^= v;
        if (x == 0)
            return true;
        return nums.size() % 2 == 0;
    }
};

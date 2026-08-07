// Link: https://leetcode.com/problems/nim-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: you lose iff n is a multiple of 4 (opponent always resets to a multiple of 4)
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

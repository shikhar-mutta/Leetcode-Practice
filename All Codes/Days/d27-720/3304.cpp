// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        // Each "+1 generation" doubles the string; the char at position k is
        // 'a' shifted by how many doublings the (0-indexed) position passed
        // through, which equals the number of set bits in (k-1).
        return 'a' + __builtin_popcount(k - 1);
    }
};

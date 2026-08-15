// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int shifts = __builtin_popcount(k - 1);
        return (char)('a' + (shifts % 26));
    }
};

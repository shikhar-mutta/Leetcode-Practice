// Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: For each char, use (c & 31) as a letter-index bit shared by
// upper/lowercase, and (c >> 5) & 1 to distinguish case (0 = upper,
// 1 = lower; masked to all-1s/all-0s via unary minus for branchless OR-ing).
// L/U track which letters appeared lowercase/uppercase; I marks a letter
// invalid the moment a lowercase occurrence is seen after its uppercase bit
// is already set (violating "all lowercase before all uppercase"). Answer
// is letters present in both cases and never marked invalid.
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unsigned int L = 0, U = 0, I = 0;
        for (char ch : word) {
            unsigned int c = (unsigned char)ch;
            if (c < 'A')
                continue;

            unsigned int bit = 1u << (c & 31);
            unsigned int lower_mask = -((c >> 5) & 1);

            I |= (U & bit) & lower_mask;
            L |= bit & lower_mask;
            U |= bit & ~lower_mask;
        }
        return __builtin_popcount(L & U & ~I);
    }
};

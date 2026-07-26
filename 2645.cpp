// Link: https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: greedily walk word tracking the next expected char in the cyclic
// a->b->c->a pattern. If the current char doesn't match, an insertion is
// needed for the expected char (advance the cycle) — repeat until it matches,
// then consume it and advance once more. After the string ends, insert
// whatever's left to complete the final "abc" block.
class Solution {
public:
    int addMinimum(string word) {
        int inserts = 0;
        char expected = 'a';   // next character we expect in the abc pattern

        for (char c : word) {
            while (c != expected) {
                ++inserts;                          // insert the expected char
                expected = (expected == 'c') ? 'a' : expected + 1;
            }
            // c matches expected; advance the cycle
            expected = (expected == 'c') ? 'a' : expected + 1;
        }
        // insert remaining characters to complete the final "abc" block
        while (expected != 'a') {
            ++inserts;
            expected = (expected == 'c') ? 'a' : expected + 1;
        }
        return inserts;
    }
};

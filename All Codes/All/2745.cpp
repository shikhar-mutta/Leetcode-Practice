// Link: https://leetcode.com/problems/construct-the-longest-new-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: "AA" and "BB" blocks must alternate (no two adjacent same blocks,
// since that would create "AAAA"/"BBBB"), so at most min(x,y) of each can be
// used in strict alternation; if x != y, one extra block of the more
// plentiful type can be tacked onto an end. "AB" blocks never create a forbidden
// substring next to anything, so all z of them are always usable. Each used
// block contributes 2 characters.
class Solution {
public:
    int longestString(int x, int y, int z) {
        int pairs = min(x, y);
        int used;
        if (x == y) {
            used = 2 * pairs + z; // all AA and BB alternate, plus all AB
        } else {
            used = 2 * pairs + 1 + z; // one extra of the larger, plus all AB
        }
        return used * 2; // each block contributes 2 characters
    }
};

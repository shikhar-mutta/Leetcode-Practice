// Link: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the allowed operations (OR two positions, or AND two
// positions and copy the result to both) can freely move, create, or
// merge 1-bits as long as at least one 1-bit exists to work with, but can
// never turn a string of all 0s into anything but all 0s, nor can an
// all-0s string ever produce a 1. So the only invariant that matters is
// whether the string contains at least one '1'; two strings are
// reachable from each other iff they agree on that.
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool sHasOne = s.find('1') != string::npos;
        bool tHasOne = target.find('1') != string::npos;
        return sHasOne == tHasOne;
    }
};

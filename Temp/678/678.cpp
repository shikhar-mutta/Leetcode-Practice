// Link: https://leetcode.com/problems/valid-parenthesis-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track range [minOpen, maxOpen] of possible open-paren counts; '(' increments both, ')' decrements both (minOpen floored at 0), '*' widens the range by -1/+1. Invalid if maxOpen goes negative; valid iff minOpen can reach 0 at the end.
class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (char c : s) {
            if (c == '(') { minOpen++; maxOpen++; }
            else if (c == ')') { minOpen--; maxOpen--; }
            else { minOpen--; maxOpen++; }
            if (maxOpen < 0) return false;
            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};

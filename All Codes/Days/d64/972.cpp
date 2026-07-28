// Link: https://leetcode.com/problems/equal-rational-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1)  SC: O(1)
// Approach: expand any repeating part "(...)" by repeating it enough
// times (20x is far more than enough given the small input lengths) to
// approximate the true value to well beyond double precision, then
// parse both as doubles and compare within a small epsilon.
class Solution {
    double expand(string s) {
        size_t open = s.find('(');
        if (open != string::npos) {
            size_t close = s.find(')');
            string repeat = s.substr(open + 1, close - open - 1);
            string expanded;
            for (int i = 0; i < 20; i++) expanded += repeat;
            s = s.substr(0, open) + expanded;
        }
        return stod(s);
    }
public:
    bool isRationalEqual(string s, string t) {
        return fabs(expand(s) - expand(t)) < 1e-9;
    }
};

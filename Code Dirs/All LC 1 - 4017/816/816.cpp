// Link: https://leetcode.com/problems/ambiguous-coordinates/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(n)
// Approach: strip parens; try every split point between the two numbers; for each side, generate all valid ways to insert a decimal point (or none), rejecting invalid leading/trailing zero patterns; combine cross product of left/right options.
class Solution {
    vector<string> validNumbers(const string& s) {
        vector<string> res;
        int n = s.size();
        // no decimal point
        if (s == "0" || s[0] != '0') res.push_back(s);
        // with decimal point at position i (1..n-1)
        for (int i = 1; i < n; i++) {
            string intPart = s.substr(0, i), fracPart = s.substr(i);
            if (intPart.size() > 1 && intPart[0] == '0') continue; // leading zero in int part
            if (fracPart.back() == '0') continue; // trailing zero in frac part
            res.push_back(intPart + "." + fracPart);
        }
        return res;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        string inner = s.substr(1, s.size()-2);
        vector<string> res;
        for (int i = 1; i < (int)inner.size(); i++) {
            auto left = validNumbers(inner.substr(0, i));
            auto right = validNumbers(inner.substr(i));
            for (auto& l : left) for (auto& r : right) res.push_back("(" + l + ", " + r + ")");
        }
        return res;
    }
};

// Link: https://leetcode.com/problems/valid-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: single-pass flags; sign only valid at start or right after e/E; '.' invalid after exponent or if repeated;
// 'e'/'E' invalid if repeated or no mantissa digit yet, and resets seenDigit to require an exponent digit too
class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false, seenDot = false, seenExp = false;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
            } else if (c == '.') {
                if (seenDot || seenExp) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                seenDigit = false;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};

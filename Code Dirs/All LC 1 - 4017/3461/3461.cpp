// Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string t;
            for (int i = 0; i + 1 < (int)s.size(); i++) {
                int d = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                t += char('0' + d);
            }
            s = t;
        }
        return s[0] == s[1];
    }
};

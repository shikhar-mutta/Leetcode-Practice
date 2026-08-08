// Link: https://leetcode.com/problems/check-if-a-string-can-break-another-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool s1GreaterOrEqual = true, s2GreaterOrEqual = true;
        for (int i = 0; i < (int)s1.size(); i++) {
            if (s1[i] < s2[i]) s1GreaterOrEqual = false;
            if (s2[i] < s1[i]) s2GreaterOrEqual = false;
        }
        return s1GreaterOrEqual || s2GreaterOrEqual;
    }
};

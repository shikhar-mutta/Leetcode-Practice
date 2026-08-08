// Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

// Link: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        set<char> chars(s.begin(), s.end());
        for (char c = 'Z'; c >= 'A'; c--) {
            if (chars.count(c) && chars.count(tolower(c))) return string(1, c);
        }
        return "";
    }
};

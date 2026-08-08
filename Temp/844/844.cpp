// Link: https://leetcode.com/problems/backspace-string-compare/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

private:
    string build(const string& s) {
        string res;
        for (char c : s) {
            if (c == '#') { if (!res.empty()) res.pop_back(); }
            else res += c;
        }
        return res;
    }
};

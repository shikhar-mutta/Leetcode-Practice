// Link: https://leetcode.com/problems/equal-rational-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRationalEqual(string s, string t) {
        return abs(parse(s) - parse(t)) < 1e-9;
    }

private:
    double parse(const string& s) {
        int paren = s.find('(');
        if (paren == (int)string::npos) return stod(s);
        string nonRepeat = s.substr(0, paren);
        string repeat = s.substr(paren + 1, s.size() - paren - 2);
        string expanded = nonRepeat;
        for (int i = 0; i < 20; i++) expanded += repeat;
        return stod(expanded);
    }
};

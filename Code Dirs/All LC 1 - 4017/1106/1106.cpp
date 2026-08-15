// Link: https://leetcode.com/problems/parsing-a-boolean-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int pos = 0;
        return parse(expression, pos);
    }

private:
    bool parse(const string& s, int& pos) {
        char c = s[pos];
        if (c == 't') { pos++; return true; }
        if (c == 'f') { pos++; return false; }
        if (c == '!') {
            pos += 2; // skip '!('
            bool res = parse(s, pos);
            pos++; // skip ')'
            return !res;
        }
        if (c == '&') {
            pos += 2;
            bool res = true;
            while (s[pos] != ')') {
                res = parse(s, pos) && res;
                if (s[pos] == ',') pos++;
            }
            pos++;
            return res;
        }
        // '|'
        pos += 2;
        bool res = false;
        while (s[pos] != ')') {
            res = parse(s, pos) || res;
            if (s[pos] == ',') pos++;
        }
        pos++;
        return res;
    }
};

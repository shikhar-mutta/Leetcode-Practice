// Link: https://leetcode.com/problems/basic-calculator-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: recursive-descent parser with grammar expr -> term (('+'|'-') term)*, term -> factor (('*'|'/') factor)*, factor -> number | '(' expr ')'. Uses a shared index into the string.
class Solution {
    string s;
    int pos;

    int parseExpr() {
        long long res = parseTerm();
        while (pos < (int)s.size()) {
            skipSpaces();
            if (pos < (int)s.size() && (s[pos] == '+' || s[pos] == '-')) {
                char op = s[pos++];
                long long t = parseTerm();
                res += (op == '+') ? t : -t;
            } else break;
        }
        return (int)res;
    }
    long long parseTerm() {
        long long res = parseFactor();
        while (true) {
            skipSpaces();
            if (pos < (int)s.size() && (s[pos] == '*' || s[pos] == '/')) {
                char op = s[pos++];
                long long f = parseFactor();
                res = (op == '*') ? res * f : res / f;
            } else break;
        }
        return res;
    }
    long long parseFactor() {
        skipSpaces();
        bool neg = false;
        if (s[pos] == '-') { neg = true; pos++; skipSpaces(); }
        else if (s[pos] == '+') { pos++; skipSpaces(); }
        long long val;
        if (s[pos] == '(') {
            pos++;
            val = parseExpr();
            skipSpaces();
            pos++; // skip ')'
        } else {
            int start = pos;
            while (pos < (int)s.size() && isdigit(s[pos])) pos++;
            val = stoll(s.substr(start, pos-start));
        }
        return neg ? -val : val;
    }
    void skipSpaces() {
        while (pos < (int)s.size() && s[pos] == ' ') pos++;
    }
public:
    int calculate(string expression) {
        s = expression;
        pos = 0;
        return parseExpr();
    }
};

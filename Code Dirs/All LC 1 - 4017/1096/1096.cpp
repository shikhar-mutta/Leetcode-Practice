// Link: https://leetcode.com/problems/brace-expansion-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> result = parseExpr(expression, pos);
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> parseExpr(const string& s, int& pos) {
        set<string> result;
        set<string> term = parseTerm(s, pos);
        result.insert(term.begin(), term.end());
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++;
            set<string> t2 = parseTerm(s, pos);
            result.insert(t2.begin(), t2.end());
        }
        return result;
    }

    set<string> parseTerm(const string& s, int& pos) {
        set<string> result = {""};
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            set<string> factor = parseFactor(s, pos);
            set<string> next;
            for (auto& a : result)
                for (auto& b : factor)
                    next.insert(a + b);
            result = next;
        }
        return result;
    }

    set<string> parseFactor(const string& s, int& pos) {
        if (s[pos] == '{') {
            pos++;
            set<string> result = parseExpr(s, pos);
            pos++; // skip '}'
            return result;
        } else {
            int start = pos;
            while (pos < (int)s.size() && islower(s[pos])) pos++;
            return {s.substr(start, pos - start)};
        }
    }
};

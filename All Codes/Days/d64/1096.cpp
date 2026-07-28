// Link: https://leetcode.com/problems/brace-expansion-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * resultSize)  SC: O(n * resultSize)
// Approach: recursive-descent parser. parseExpr handles comma-separated
// terms (union of sets); parseTerm handles concatenated factors
// (cartesian product of sets, joining strings); parseFactor handles a
// bare lowercase word or a brace-grouped sub-expression. Final result
// is the sorted, deduplicated union set.
class Solution {
    string s;
    int pos;

    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++;
            set<string> t = parseTerm();
            result.insert(t.begin(), t.end());
        }
        return result;
    }
    set<string> parseTerm() {
        vector<set<string>> factors;
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            factors.push_back(parseFactor());
        }
        set<string> result = {""};
        for (auto& f : factors) {
            set<string> next;
            for (auto& a : result)
                for (auto& b : f)
                    next.insert(a + b);
            result = next;
        }
        return result;
    }
    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++; // skip '{'
            set<string> r = parseExpr();
            pos++; // skip '}'
            return r;
        }
        int start = pos;
        while (pos < (int)s.size() && islower(s[pos])) pos++;
        return {s.substr(start, pos - start)};
    }
public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }
};

// Link: https://leetcode.com/problems/basic-calculator-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) roughly SC: O(n)
// Approach: tokenize (parens are separate tokens even without surrounding spaces), recursive-descent parse expr->term->factor. Represent a polynomial as map<sorted vector<string> vars, coefficient>; known variables substitute to numeric constants at parse time. Multiply merges var-lists; add merges by key. Output sorted by degree desc, then lexicographic var-list.
class Solution {
    unordered_map<string,int> val;
    vector<string> tokens;
    size_t pos;

    vector<string> tokenize(const string& s) {
        vector<string> toks;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == ' ') { i++; continue; }
            if (s[i] == '(' || s[i] == ')') { toks.push_back(string(1, s[i])); i++; continue; }
            int start = i;
            while (i < n && s[i] != ' ' && s[i] != '(' && s[i] != ')') i++;
            toks.push_back(s.substr(start, i-start));
        }
        return toks;
    }

    using Poly = map<vector<string>, long long>;

    Poly mulPoly(const Poly& a, const Poly& b) {
        Poly res;
        for (auto& [va, ca] : a) {
            for (auto& [vb, cb] : b) {
                vector<string> merged = va;
                merged.insert(merged.end(), vb.begin(), vb.end());
                sort(merged.begin(), merged.end());
                res[merged] += ca * cb;
            }
        }
        return res;
    }
    Poly addPoly(const Poly& a, const Poly& b, int sign) {
        Poly res = a;
        for (auto& [v, c] : b) res[v] += sign * c;
        return res;
    }

    Poly parseExpr() {
        Poly res = parseTerm();
        while (pos < tokens.size() && (tokens[pos] == "+" || tokens[pos] == "-")) {
            int sign = tokens[pos] == "+" ? 1 : -1;
            pos++;
            res = addPoly(res, parseTerm(), sign);
        }
        return res;
    }
    Poly parseTerm() {
        Poly res = parseFactor();
        while (pos < tokens.size() && tokens[pos] == "*") {
            pos++;
            res = mulPoly(res, parseFactor());
        }
        return res;
    }
    Poly parseFactor() {
        if (tokens[pos] == "(") {
            pos++;
            Poly res = parseExpr();
            pos++; // skip ')'
            return res;
        }
        string tok = tokens[pos++];
        Poly res;
        if (isdigit(tok[0]) || (tok[0]=='-' && tok.size()>1)) {
            res[{}] = stoll(tok);
        } else if (val.count(tok)) {
            res[{}] = val[tok];
        } else {
            res[{tok}] = 1;
        }
        return res;
    }

public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for (size_t i = 0; i < evalvars.size(); i++) val[evalvars[i]] = evalints[i];
        tokens = tokenize(expression);
        pos = 0;
        Poly result = parseExpr();
        vector<pair<vector<string>, long long>> terms;
        for (auto& [v, c] : result) if (c != 0) terms.push_back({v, c});
        sort(terms.begin(), terms.end(), [](auto& a, auto& b){
            if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
            return a.first < b.first;
        });
        vector<string> res;
        for (auto& [v, c] : terms) {
            string t = to_string(c);
            for (auto& var : v) t += "*" + var;
            res.push_back(t);
        }
        if (res.empty()) res.push_back("0");
        return res;
    }
};

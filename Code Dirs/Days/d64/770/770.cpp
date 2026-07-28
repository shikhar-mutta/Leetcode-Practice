// Link: https://leetcode.com/problems/basic-calculator-iv/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2) ish (polynomial multiplication dominates, n = expr length) SC: O(n^2)
// Approach: represent the expression as a polynomial: map from a sorted
// vector of variable names (a monomial, with repetition for powers) to
// its coefficient. Recursive-descent parse expr->term->factor handling
// +,-,*,parentheses, and variables (substituted immediately if present
// in the evaluation map). Combine sub-polynomials via add/multiply.
// Finally emit non-zero terms sorted by degree desc, then lexicographic.
class Solution {
    using Term = vector<string>;
    using Poly = map<Term, long long>;
    unordered_map<string,int> evalMap;
    vector<string> tokens;
    int pos;

    Poly addPoly(Poly a, const Poly& b, int sign) {
        for (auto& [t, c] : b) {
            a[t] += sign * c;
            if (a[t] == 0) a.erase(t);
        }
        return a;
    }
    Poly mulPoly(const Poly& a, const Poly& b) {
        Poly res;
        for (auto& [t1, c1] : a) {
            for (auto& [t2, c2] : b) {
                Term merged = t1;
                merged.insert(merged.end(), t2.begin(), t2.end());
                sort(merged.begin(), merged.end());
                res[merged] += c1 * c2;
            }
        }
        for (auto it = res.begin(); it != res.end(); ) {
            if (it->second == 0) it = res.erase(it);
            else ++it;
        }
        return res;
    }
    Poly parseExpr() {
        Poly poly = parseTerm();
        while (pos < (int)tokens.size() && (tokens[pos] == "+" || tokens[pos] == "-")) {
            int sign = (tokens[pos] == "+") ? 1 : -1;
            pos++;
            Poly t = parseTerm();
            poly = addPoly(poly, t, sign);
        }
        return poly;
    }
    Poly parseTerm() {
        Poly poly = parseFactor();
        while (pos < (int)tokens.size() && tokens[pos] == "*") {
            pos++;
            Poly f = parseFactor();
            poly = mulPoly(poly, f);
        }
        return poly;
    }
    Poly parseFactor() {
        string tok = tokens[pos];
        if (tok == "(") {
            pos++;
            Poly p = parseExpr();
            pos++; // skip ")"
            return p;
        }
        pos++;
        if (isdigit(tok[0])) {
            Poly p;
            p[{}] = stoll(tok);
            return p;
        }
        if (evalMap.count(tok)) {
            Poly p;
            p[{}] = evalMap[tok];
            return p;
        }
        Poly p;
        p[{tok}] = 1;
        return p;
    }
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for (int i = 0; i < (int)evalvars.size(); i++) evalMap[evalvars[i]] = evalints[i];

        tokens.clear();
        int n = expression.size();
        for (int i = 0; i < n; ) {
            char c = expression[i];
            if (c == ' ') { i++; continue; }
            if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*') {
                tokens.push_back(string(1, c));
                i++;
            } else {
                int j = i;
                while (j < n && expression[j] != ' ' && expression[j] != '(' &&
                       expression[j] != ')' && expression[j] != '+' &&
                       expression[j] != '-' && expression[j] != '*') j++;
                tokens.push_back(expression.substr(i, j - i));
                i = j;
            }
        }
        pos = 0;

        Poly result = parseExpr();

        vector<pair<Term,long long>> terms(result.begin(), result.end());
        sort(terms.begin(), terms.end(), [](auto& a, auto& b) {
            if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
            return a.first < b.first;
        });

        vector<string> ans;
        for (auto& [t, c] : terms) {
            string s = to_string(c);
            for (auto& v : t) s += "*" + v;
            ans.push_back(s);
        }
        return ans;
    }
};

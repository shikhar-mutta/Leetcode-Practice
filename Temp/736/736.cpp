// Link: https://leetcode.com/problems/parse-lisp-expression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: recursive-descent parse of the s-expression; each scope is a vector<map> pushed/popped, "let" evaluates var/expr pairs sequentially binding into a new scope (later bindings can see earlier ones), "add"/"mult" evaluate two subexpressions.
class Solution {
    unordered_map<string, vector<int>> scope;

    string parseToken(const string& e, int& i) {
        int start = i;
        int depth = 0;
        while (i < (int)e.size()) {
            if (e[i] == '(') depth++;
            else if (e[i] == ')') { if (depth == 0) break; depth--; }
            else if (e[i] == ' ' && depth == 0) break;
            i++;
        }
        return e.substr(start, i - start);
    }

    int eval(const string& e) {
        if (e[0] != '(') {
            if (isdigit(e[0]) || e[0] == '-') return stoi(e);
            return scope[e].back();
        }
        string inner = e.substr(1, e.size()-2);
        int i = 0;
        string cmd = parseToken(inner, i);
        if (i < (int)inner.size()) i++; // skip space
        if (cmd == "add" || cmd == "mult") {
            string a = parseToken(inner, i); if (i < (int)inner.size()) i++;
            string b = parseToken(inner, i);
            int va = eval(a), vb = eval(b);
            return cmd == "add" ? va + vb : va * vb;
        } else { // let
            vector<string> tokens;
            while (true) {
                string tok = parseToken(inner, i);
                tokens.push_back(tok);
                if (i < (int)inner.size()) i++;
                if (i >= (int)inner.size()) break;
            }
            int n = tokens.size();
            vector<string> boundNames;
            int idx = 0;
            while (idx + 1 < n) {
                string name = tokens[idx];
                string valExpr = tokens[idx+1];
                int val = eval(valExpr);
                scope[name].push_back(val);
                boundNames.push_back(name);
                idx += 2;
            }
            string finalExpr = tokens[n-1];
            int result = eval(finalExpr);
            for (auto& name : boundNames) scope[name].pop_back();
            return result;
        }
    }
public:
    int evaluate(string expression) {
        return eval(expression);
    }
};

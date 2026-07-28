// Link: https://leetcode.com/problems/parse-lisp-expression/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: recursive-descent parser over a shared variable scope map.
// For "(let v1 e1 v2 e2 ... expr)", bind each var in sequence (later
// vars can reference earlier ones, and self-shadowing is allowed since
// each var's value is evaluated before it's bound), saving/restoring
// prior bindings so sibling scopes don't leak. "(add a b)"/"(mult a b)"
// evaluate both operands; tokens are parsed by scanning balanced
// parens or up to the next space/close-paren for atoms.
class Solution {
    unordered_map<string, long long> scope;

    // parses one token/expression starting at i, returns (value, nextIndex)
    pair<long long,int> parse(const string& s, int i) {
        if (s[i] != '(') {
            int j = i;
            while (j < (int)s.size() && s[j] != ' ' && s[j] != ')') j++;
            string tok = s.substr(i, j - i);
            long long val;
            if (isdigit(tok[0]) || tok[0] == '-') val = stoll(tok);
            else val = scope[tok];
            return {val, j};
        }
        // s[i] == '(' : parse operator
        int j = i + 1;
        int opStart = j;
        while (s[j] != ' ') j++;
        string op = s.substr(opStart, j - opStart);
        j++; // skip space

        if (op == "let") {
            vector<pair<string, long long>> saved;
            while (true) {
                int k = j;
                while (k < (int)s.size() && s[k] != ' ' && s[k] != ')') k++;
                string tokOrVar = s.substr(j, k - j);
                // check if this is the final expression (next non-space is ')')
                // determine by peeking: if after this token/expr comes ')', it's the final expr
                if (s[j] == '(') {
                    // this is the final expression (since var names never start with '(')
                    auto [val, ni] = parse(s, j);
                    for (auto it = saved.rbegin(); it != saved.rend(); ++it) {
                        if (it->second == LLONG_MIN) scope.erase(it->first);
                        else scope[it->first] = it->second;
                    }
                    return {val, ni + 1}; // skip closing ')'
                }
                // tokOrVar is a variable name; check what follows
                int afterVar = k;
                if (s[afterVar] == ')') {
                    // this token itself is the final expression (a bare variable)
                    long long val = scope[tokOrVar];
                    for (auto it = saved.rbegin(); it != saved.rend(); ++it) {
                        if (it->second == LLONG_MIN) scope.erase(it->first);
                        else scope[it->first] = it->second;
                    }
                    return {val, afterVar + 1};
                }
                // otherwise tokOrVar is a var name to bind; parse its value expr next
                int valStart = afterVar + 1;
                auto [val, ni] = parse(s, valStart);
                long long oldVal = scope.count(tokOrVar) ? scope[tokOrVar] : LLONG_MIN;
                saved.push_back({tokOrVar, oldVal});
                scope[tokOrVar] = val;
                j = (s[ni] == ' ') ? ni + 1 : ni;
            }
        } else {
            auto [a, ni1] = parse(s, j);
            int j2 = (s[ni1] == ' ') ? ni1 + 1 : ni1;
            auto [b, ni2] = parse(s, j2);
            long long val = (op == "add") ? a + b : a * b;
            return {val, ni2 + 1}; // skip closing ')'
        }
    }
public:
    int evaluate(string expression) {
        auto [val, idx] = parse(expression, 0);
        return (int)val;
    }
};

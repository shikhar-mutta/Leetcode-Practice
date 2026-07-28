// Link: https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n) recursion stack
// Approach: recursive descent parse computing pair (cost0,cost1) = minimum
// operations (bit flips or operator flips) to force the subexpression to
// evaluate to 0 or 1. For any operator combine, compute both the AND-result
// and OR-result costs, then pick min(natural, 1 + other) since we may flip
// the operator itself for cost 1. Answer = cost to reach the opposite of the
// expression's current value.
class Solution {
    string s;
    int pos;

    pair<int,int> parseOperand() {
        if (s[pos] == '(') {
            pos++; // skip '('
            auto res = parseExpr();
            pos++; // skip ')'
            return res;
        } else {
            int v = s[pos] - '0';
            pos++;
            return v == 0 ? make_pair(0, 1) : make_pair(1, 0);
        }
    }

    pair<int,int> combine(pair<int,int> a, pair<int,int> b, char op) {
        int and0 = min({a.first + b.first, a.first + b.second, a.second + b.first});
        int and1 = a.second + b.second;
        int or0 = a.first + b.first;
        int or1 = min({a.first + b.second, a.second + b.first, a.second + b.second});
        if (op == '&') {
            return {min(and0, 1 + or0), min(and1, 1 + or1)};
        } else {
            return {min(or0, 1 + and0), min(or1, 1 + and1)};
        }
    }

    pair<int,int> parseExpr() {
        auto result = parseOperand();
        while (pos < (int)s.size() && (s[pos] == '&' || s[pos] == '|')) {
            char op = s[pos];
            pos++;
            auto rhs = parseOperand();
            result = combine(result, rhs, op);
        }
        return result;
    }
public:
    int minOperationsToFlip(string expression) {
        s = expression;
        pos = 0;
        auto res = parseExpr();
        // whichever cost is 0 reflects the current value; answer is the other
        return res.first == 0 ? res.second : res.first;
    }
};

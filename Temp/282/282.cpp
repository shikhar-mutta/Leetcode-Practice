// Link: https://leetcode.com/problems/expression-add-operators/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^n)  SC: O(n) recursion depth
// Approach: backtrack over each split, tracking running value and last operand
// (for correct +/- precedence handling of '*'), skip splits with leading zero
class Solution {
    vector<string> res;
    string num;
    int target;

    void backtrack(int pos, string expr, long long value, long long last) {
        if (pos == (int)num.size()) {
            if (value == target) res.push_back(expr);
            return;
        }
        for (int i = pos; i < (int)num.size(); i++) {
            if (i > pos && num[pos] == '0') break;
            string part = num.substr(pos, i - pos + 1);
            long long cur = stoll(part);
            if (pos == 0) {
                backtrack(i + 1, part, cur, cur);
            } else {
                backtrack(i + 1, expr + "+" + part, value + cur, cur);
                backtrack(i + 1, expr + "-" + part, value - cur, -cur);
                backtrack(i + 1, expr + "*" + part, value - last + last * cur, last * cur);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        if (!num.empty()) backtrack(0, "", 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

// Link: https://leetcode.com/problems/ternary-expression-parser/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: scan right to left with a stack; on '?' pop true/false branch
// values and the condition, push the chosen one back
class Solution {
public:
    string parseTernary(string expression) {
        vector<char> stk;
        for (int i = expression.size() - 1; i >= 0; i--) {
            char c = expression[i];
            if (c == '?') {
                char t = stk.back(); stk.pop_back();
                char f = stk.back(); stk.pop_back();
                char cond = expression[--i];
                stk.push_back(cond == 'T' ? t : f);
            } else if (c != ':') {
                stk.push_back(c);
            }
        }
        return string(1, stk.back());
    }
};

// Link: https://leetcode.com/problems/score-of-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') st.push(0);
            else {
                int v = st.top(); st.pop();
                int add = (v == 0) ? 1 : 2 * v;
                st.top() += add;
            }
        }
        return st.top();
    }
};

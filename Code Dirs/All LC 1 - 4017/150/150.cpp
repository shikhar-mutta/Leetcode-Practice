// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: stack; on an operator, pop b then a (in that order since a came first), push a op b
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (tok == "+") st.push(a + b);
                else if (tok == "-") st.push(a - b);
                else if (tok == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};

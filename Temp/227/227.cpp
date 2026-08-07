// Link: https://leetcode.com/problems/basic-calculator-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: stack-based; push each term (applying * and / immediately against the top since they bind
// tighter), then sum the stack at the end for the +/- terms
class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long num = 0;
        char op = '+';
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if ((!isdigit(c) && !isspace(c)) || i == (int)s.size() - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') { long long t = st.top(); st.pop(); st.push(t * num); }
                else if (op == '/') { long long t = st.top(); st.pop(); st.push(t / num); }
                op = c;
                num = 0;
            }
        }
        long long total = 0;
        while (!st.empty()) { total += st.top(); st.pop(); }
        return (int)total;
    }
};

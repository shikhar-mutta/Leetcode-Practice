// Link: https://leetcode.com/problems/basic-calculator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: stack-based; push (result,sign) on '(', combine on ')'; long long throughout since the
// running digit-accumulator can transiently exceed INT_MAX before the sign is applied (e.g. "-2147483648")
class Solution {
public:
    int calculate(string s) {
        stack<pair<long long,int>> st;
        long long result = 0;
        int sign = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                long long num = 0;
                while (i < (int)s.size() && isdigit(s[i])) { num = num * 10 + (s[i] - '0'); i++; }
                i--;
                result += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push({result, sign});
                result = 0;
                sign = 1;
            } else if (c == ')') {
                auto [prevResult, prevSign] = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }
        }
        return (int)result;
    }
};

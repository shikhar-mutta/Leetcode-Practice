// Link: https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: stack of indices seeded with -1 sentinel; push '(' index, pop on ')' —
// empty after pop means unmatched (push current index as new base), else length = i - stack.top()
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else best = max(best, i - st.top());
            }
        }
        return best;
    }
};

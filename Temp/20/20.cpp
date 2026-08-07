// Link: https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: stack of open brackets; on a closer, top must match its pair, else invalid; stack must be empty at the end
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> pair = {{')','('},{']','['},{'}','{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (st.empty() || st.top() != pair[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

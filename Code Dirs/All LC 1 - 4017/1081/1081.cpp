// Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < (int)s.size(); i++) lastIdx[s[i]-'a'] = i;
        vector<bool> inStack(26, false);
        string st;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c-'a']) continue;
            while (!st.empty() && st.back() > c && lastIdx[st.back()-'a'] > i) {
                inStack[st.back()-'a'] = false;
                st.pop_back();
            }
            st += c;
            inStack[c-'a'] = true;
        }
        return st;
    }
};

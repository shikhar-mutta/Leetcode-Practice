// Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string st;
        for (char c : s) {
            st += c;
            if (st.size() >= 3 && st.substr(st.size()-3) == "abc") {
                st.erase(st.size()-3);
            }
        }
        return st.empty();
    }
};

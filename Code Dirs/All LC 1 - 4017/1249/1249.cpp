// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk;
        vector<bool> remove(s.size(), false);
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') stk.push_back(i);
            else if (s[i] == ')') {
                if (!stk.empty()) stk.pop_back();
                else remove[i] = true;
            }
        }
        for (int i : stk) remove[i] = true;
        string res;
        for (int i = 0; i < (int)s.size(); i++) if (!remove[i]) res += s[i];
        return res;
    }
};

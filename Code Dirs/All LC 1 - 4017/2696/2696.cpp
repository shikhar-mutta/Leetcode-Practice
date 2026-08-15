// Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        string stk;
        for (char c : s) {
            if (!stk.empty() && ((stk.back() == 'A' && c == 'B') || (stk.back() == 'C' && c == 'D'))) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk.size();
    }
};

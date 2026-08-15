// Link: https://leetcode.com/problems/make-the-string-great/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && abs(stack.back() - c) == 32) {
                stack.pop_back();
            } else {
                stack += c;
            }
        }
        return stack;
    }
};

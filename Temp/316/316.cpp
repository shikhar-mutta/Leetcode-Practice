// Link: https://leetcode.com/problems/remove-duplicate-letters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
// Approach: monotonic stack - pop a larger char off the stack if it still
// appears later and isn't already used, to keep the lexicographically smallest result
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastIdx[26];
        for (int i = 0; i < (int)s.size(); i++) lastIdx[s[i] - 'a'] = i;

        string stk;
        bool inStack[26] = {false};
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;
            while (!stk.empty() && stk.back() > c && lastIdx[stk.back() - 'a'] > i) {
                inStack[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk += c;
            inStack[c - 'a'] = true;
        }
        return stk;
    }
};

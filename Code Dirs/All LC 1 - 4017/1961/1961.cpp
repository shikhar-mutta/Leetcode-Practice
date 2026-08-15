// Link: https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string cur;
        for (auto& w : words) {
            cur += w;
            if (cur == s) return true;
            if (cur.size() > s.size()) return false;
        }
        return false;
    }
};

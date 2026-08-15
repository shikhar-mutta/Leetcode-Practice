// Link: https://leetcode.com/problems/replace-all-digits-with-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        string res = s;
        for (int i = 1; i < (int)s.size(); i += 2) {
            res[i] = s[i-1] + (s[i] - '0');
        }
        return res;
    }
};
